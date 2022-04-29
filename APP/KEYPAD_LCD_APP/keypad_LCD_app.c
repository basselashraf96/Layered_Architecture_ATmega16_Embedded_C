/*
 * keypad_LCD_app.c
 *
 *  Created on: Apr 29, 2022
 *      Author: Basel Ashraf
 */


#include "../../HAL/KEYPAD/keypad.h"
#include "../../HAL/LCD/lcd.h"


int keypad_lcd_app_test(void)
{
	uint8 buttonPressed = 0;
	LCD_init();
	LCD_displayCharacter('I');
	while(1)
	{
		buttonPressed = KeyPad_getPressedKey();

		switch(buttonPressed)
		{
		case 1:
			LCD_goToRowColumn(0,0);
			LCD_displayCharacter('a');
			break;
		case 5:
			LCD_goToRowColumn(0,0);
			LCD_displayCharacter('H');
			break;
		default:
			break;
		}
	}
	return 0;
}
