/*
 * uart.h
 *
 *  Created on: Apr 30, 2022
 *      Author: Basel Ashraf
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include "uart_reg.h"
#include <avr/interrupt.h>

/************************************
 * 			CONFIGURATIONS
 *************************************/
#define F_CPU 1000000UL
#define UART_BAUD_RATE 9600

#define ASYNCHRONOUS 0
#define SYNCHRONOUS  1
#define UART_MODE_SELECT ASYNCHRONOUS

#define UART_DOUBLE_SPEED_ENABLE ENABLE /* Select between ENABLE and DISABLE */

#define UART_INTERRUPT_ENABLE    DISABLE /* Select between ENABLE and DISABLE */

#define UART_RX_ENABLE           ENABLE /* Select between ENABLE and DISABLE */
#define UART_TX_ENABLE           ENABLE /* Select between ENABLE and DISABLE */

#if(UART_MODE_SELECT == SYNCHRONOUS)
#define UART_CLK_TX_RISING_RX_FALLING_EDGE 0
#define UART_CLK_TX_FALLING_RX_RISING_EDGE 1

#define UART_CLK_EDGE_SELECT_SYNCH_MODE    UART_CLK_TX_RISING_RX_FALLING_EDGE

#endif

/************************************
 * 			Types Declaration
 *************************************/

typedef enum
{
	UART_PARITY_DESABLED , UART_Reserved, UART_EVEN_PARITY , UART_ODD_PARITY

}Parity_Mode_Select_t;

typedef enum
{
	UART_ONE_BIT , UART_TWO_BIT

}Stop_Bit_Number_Select_t;

typedef enum
{
	UART_5_Bit , UART_6_Bit , UART_7_Bit , UART_8_Bit , UART_Reserved1 , UART_Reserved2 , UART_Reserved3 , UART_9_Bit

}Character_Size_Select_t;

typedef struct
{
	Parity_Mode_Select_t     Parity_Mode_Select;
	Stop_Bit_Number_Select_t Stop_Bit_Number_Select;
	Character_Size_Select_t  Character_Size_Select;

}Uart_Config_t;

/************************************
 * 			Function Prototype
 *************************************/
void UART_init(Uart_Config_t* Config);

void UART_sendByte(const uint8 data);

uint8 UART_recieveByte(void);

void UART_sendString(const uint8 *Str);

void UART_receiveString(uint8 *Str); // Receive until #

#endif /* MCAL_UART_UART_H_ */
