/*
 * uart_app_test.c
 *
 *  Created on: May 5, 2022
 *      Author: Basel Ashraf
 */


#include "../../MCAL/UART/uart.h"
#include <util/delay.h>

#define MC1_READY 0x16
#define MC2_READY 0x15

int uart_app_test(void)
{
	Uart_Config_t Uart_Config = {UART_PARITY_DESABLED , UART_ONE_BIT , UART_8_Bit};
	UART_init(&Uart_Config);

	while(1)
	{
		UART_SerialWrite("AHMED#");
		UART_SerialWrite("Basel#");
		while(1);


	}

	return 0;
}
