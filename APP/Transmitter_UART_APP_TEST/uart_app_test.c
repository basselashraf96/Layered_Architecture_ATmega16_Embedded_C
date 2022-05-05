/*
 * uart_app_test.c
 *
 *  Created on: May 5, 2022
 *      Author: Basel Ashraf
 */


#include "../../MCAL/UART/uart.h"
#include <util/delay.h>


int uart_app_test(void)
{
	Uart_Config_t Uart_Config = {UART_PARITY_DESABLED , UART_ONE_BIT , UART_8_Bit};
	UART_init(&Uart_Config);
	while(1)
	{
		UART_sendString("Bassel#");
		_delay_ms(50);

	}

	return 0;
}
