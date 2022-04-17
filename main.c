/*
 * main.c
 *
 *  Created on: Apr 17, 2022
 *      Author: Basel Ashraf
 */


#include "MCAL/DIO/DIO_REG.h"


int main(void)
{
	DDRA |= (1<<0);
	PORTA &= ~(1<<0);
	while(1)
	{
		PORTA &= ~(1<<0);
	}

	return 0;
}
