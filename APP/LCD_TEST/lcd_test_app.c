/*
 * lcd_test_app.c
 *
 *  Created on: Apr 24, 2022
 *      Author: Basel Ashraf
 */


#include "../../HAL/LCD/lcd.h"
#include "../../MCAL/DIO/DIO.h"


int lcd_test_app(void)
{
	LCD_init();

	while(1)
	{
		LCD_displayStringRowColumn(0,0,"AHMED");
		while(1);
	}
	return 0;
}
