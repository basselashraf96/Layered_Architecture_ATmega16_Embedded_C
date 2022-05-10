/*
 * uart.c
 *
 *  Created on: Apr 30, 2022
 *      Author: Basel Ashraf
 */


#include "uart.h"
#include "../../UTILS/common_macros.h"
#include <string.h>
#include <util/delay.h>
/*********************************************************
 * 				Global Variables & flags
 *********************************************************/
#if(UART_INTERRUPT_ENABLE == ENABLE)

uint8 UART_TX_Buffer[UART_Buffer_Size];
static volatile uint8 UART_TX_ReadPos = 0;
static volatile uint8 UART_TX_WritePos = 0;

uint8 UART_RX_Buffer[UART_Buffer_Size];
static volatile uint8 UART_RX_ReadPos = 0;
static volatile uint8 UART_RX_WritePos = 0;
static volatile bool f_UART_ReadFlag = FALSE;
static volatile bool f_UART_RecieveComplete = FALSE;
static volatile uint8 UART_ReadByte = 0;

#endif
/*********************************************************/

/*********************************************************
 * 				BAUD PRESCALER
 *********************************************************/
#if(UART_MODE_SELECT == ASYNCHRONOUS)

#if(UART_DOUBLE_SPEED_ENABLE == DISABLE)

#define UART_BAUD_RATE_PRESCALE   ((F_CPU/(UART_BAUD_RATE*6UL))-1)

#elif(UART_DOUBLE_SPEED_ENABLE == ENABLE)

#define UART_BAUD_RATE_PRESCALE   ((F_CPU/(UART_BAUD_RATE*8UL))-1)

#endif

#elif(UART_MODE_SELECT == SYNCHRONOUS)

#define UART_BAUD_RATE_PRESCALE   ((F_CPU/(UART_BAUD_RATE*2UL))-1)

#endif

/*********************************************************/

/*********************************************************
 * 			INTERRUPT SERVICE ROUTINE
 *********************************************************/
#if(UART_INTERRUPT_ENABLE == ENABLE)

ISR(USART_RXC_vect)
{
	UART_ReadByte = UDR; /* Read every byte Sent from the transmitter */

	/* Add the sent byte to the receiver buffer only if the terminator character was not sent('#')
	 * OR
	 * When UART_SerialRead function is Used in your application */

	if(f_UART_ReadFlag == TRUE || UART_ReadByte != '#')
	{
		UART_RX_Buffer[UART_RX_ReadPos] = UART_ReadByte; /* Add received byte to the receiver buffer */
		UART_RX_ReadPos++; /* Point to the next index in the receiver buffer */
		f_UART_ReadFlag = FALSE; /* The received byte is read so drop the read flag */
	}
	else
	{
		/* If every byte was sent by the transmitter is added to the receiver buffer
		 * raise the flag to be able to use UART_SerialRead function */
		f_UART_RecieveComplete = TRUE;
	}
}
ISR(USART_TXC_vect)
{
	_delay_ms(50); /* A delay to give time for the transmitter to send and receive data properly */

	/* Stop sending data after the buffer is completely read where the index of read position reaches the index of write position */
	if(UART_TX_ReadPos != UART_TX_WritePos)
	{
		UDR = UART_TX_Buffer[UART_TX_ReadPos]; /*Get data from the transmitter buffer and put it in the UDR register */
		UART_TX_ReadPos++; /* Gets the next data from the transmitter buffer */
	}
	else
	{
		/* Adds Null character after last character in the transmitter buffer array for strcmp function
		 * To be able to compare entered input string from UART_SerialWrite function
		 * with the transmitter buffer array to prevent sending the same data over and over again */
		UART_TX_Buffer[UART_TX_ReadPos] = '\0';

		UART_TX_ReadPos = 0; /* Reset read index to read new data after successful sending the old data */
		UART_TX_WritePos = 0; /* Reset write index to write new data successful sending the old data    */
	}

}
//ISR(USART_UDRE_vect)
//{
//
//}

#endif
/*********************************************************/

void UART_init(Uart_Config_t* Config)
{
	CLEAR_BIT(UCSRA , FE); /* see page 157 ATmega16 DATASHEET*/
	CLEAR_BIT(UCSRA , DOR);

#if((UART_DOUBLE_SPEED_ENABLE == ENABLE) && (UART_MODE_SELECT == ASYNCHRONOUS))

	SET_BIT(UCSRA , U2X); /* UART double speed mode is only active in asynchronous mode */

#endif

#if(UART_INTERRUPT_ENABLE == ENABLE)

	SET_BIT(SREG , 7); /*enable I-bit to enable interrupt */
	SET_BIT(UCSRB , RXCIE);
	SET_BIT(UCSRB , TXCIE);
	//	SET_BIT(UCSRB , UDRIE);

#endif

#if(UART_RX_ENABLE == ENABLE)

	SET_BIT(UCSRB , RXEN);

#endif

#if(UART_TX_ENABLE == ENABLE)

	SET_BIT(UCSRB , TXEN);

#endif

	/* URSEL set to one to select UCSRC register instead of UBBRH */
	SET_BIT(UCSRC , URSEL);

#if(UART_MODE_SELECT == ASYNCHRONOUS)

	CLEAR_BIT(UCSRC , UMSEL); /* UART mode select (ASYNCHRONOUS) */

#elif(UART_MODE_SELECT == SYNCHRONOUS)

	SET_BIT(UCSRC , UMSEL); /* UART mode select (SYNCHRONOUS) */

#endif

	UCSRC = (UCSRC & 0xCF) | (Config->Parity_Mode_Select << 4);

	UCSRC = (UCSRC & 0xF7) | (Config->Stop_Bit_Number_Select << 3);

	UCSRC = (UCSRC & 0xF9) | ((Config->Character_Size_Select & 0x03) << 1); /* Mask UCSZ0 and UCSZ1 from UCSZ2        */
	UCSRB = (UCSRB & 0xFB) | ((Config->Character_Size_Select & 0x04) << 2); /* Mask UCSZ2 from UCSZ0 and UCSZ1        */

#if(UART_MODE_SELECT == SYNCHRONOUS)

#if(UART_CLK_EDGE_SELECT_SYNCH_MODE == UART_CLK_TX_RISING_RX_FALLING_EDGE)

	CLEAR_BIT(UCSRC , UCPOL);

#elif(UART_CLK_EDGE_SELECT_SYNCH_MODE == UART_CLK_TX_FALLING_RX_RISING_EDGE)

	SET_BIT(UCSRC , UCPOL);

#endif

#endif

	/* Selected Baud Rate */
	UBRRL = UART_BAUD_RATE_PRESCALE;
	UBRRH = ((UART_BAUD_RATE_PRESCALE & 0xF0)>>8);
}

#if(UART_INTERRUPT_ENABLE == ENABLE)

/* Adding byte to the transmitter buffer */
void UART_TX_AppendSerial(uint8 character)
{
	UART_TX_Buffer[UART_TX_WritePos] = character;
	UART_TX_WritePos++;
}

/* Enter required data as a string to be sent to the receiver buffer */
void UART_SerialWrite(uint8 *Str)
{
	/* Compare old sent string with the new input string to prevent sending same data one after the other */
	if(strcmp(Str , UART_TX_Buffer))
	{
		uint8 counter = 0;

		/* Append data till the null character */
		while(counter < strlen(Str))
		{
			UART_TX_AppendSerial(Str[counter]); /* Add Each STR character to the Transmitter buffer array */
			counter++;
		}
		if(BIT_IS_SET(UCSRA , UDRE))
		{
			UDR = 0; /* To Fire Transmit complete ISR */
		}
	}
}

void UART_SerialRead(uint8 *Str)
{
	/* Only works if the data sent from the transmitter is complete transfered to the receiver buffer (the flag is raised) */
	if(f_UART_RecieveComplete == TRUE)
	{
		while(UART_RX_WritePos < UART_RX_ReadPos) /* Get all the data from the receiver buffer */
		{
			Str[UART_RX_WritePos] = UART_RX_Buffer[UART_RX_WritePos]; /* Copy the data to the user string */
			UART_RX_WritePos++;
		}
		f_UART_ReadFlag = TRUE; /* Indicates that the data was successfully read */
		UART_RX_ReadPos = 0;  /* Reset read index to read new data after successful Reading the old data */
		UART_RX_WritePos = 0; /* Reset write index to write new data after successful copying the old data */
		f_UART_RecieveComplete = FALSE; /* Drop the flag to receive new data */
	}
}

#else
void UART_sendByte(const uint8 data)
{
	while(BIT_IS_CLEAR(UCSRA , UDRE)); /* Wait till the UDR is empty */
	UDR = data;
}

uint8 UART_recieveByte(void)
{
	while(BIT_IS_CLEAR(UCSRA,RXC)){} /* Wait till the receive is complete */
	return UDR;
}

/* Must terminate the string with '#' character for the receiver to able to read the string properly */
void UART_sendString(const uint8 *Str)
{
	uint8 counter = 0;
	while(Str[counter] != '\0')
	{
		UART_sendByte(Str[counter]); /* Send each character of the string one by one */
		counter++;
	}

}

void UART_receiveString(uint8 *Str) /* Receive until '#' character */
{
	uint8 counter = 0;
	Str[counter] = UART_recieveByte();
	while(Str[counter] != '#')
	{
		counter++;
		Str[counter] = UART_recieveByte();

	}
	Str[counter] = '\0';
}
#endif
