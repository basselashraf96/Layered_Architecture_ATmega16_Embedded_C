/*
 * uart.c
 *
 *  Created on: Apr 30, 2022
 *      Author: Basel Ashraf
 */


#include "uart.h"
#include "../../UTILS/common_macros.h"

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
	SET_BIT(UCSRB , UDRIE);

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

	UBRRL = UART_BAUD_RATE_PRESCALE;
	UBRRH = ((UART_BAUD_RATE_PRESCALE & 0xF0)>>8);
}

void UART_sendByte(const uint8 data)
{
	while(BIT_IS_CLEAR(UCSRA , UDRE));
	UDR = data;
}

uint8 UART_recieveByte(void)
{
	while(BIT_IS_CLEAR(UCSRA,RXC)){}
	return UDR;
}

void UART_sendString(const uint8 *Str)
{
	uint8 counter = 0;
	while(Str[counter] != '\0')
	{
		UART_sendByte(Str[counter]);
		counter++;
	}

}

void UART_receiveString(uint8 *Str) // Receive until #
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
