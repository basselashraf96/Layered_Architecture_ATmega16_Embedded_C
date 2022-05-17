/*
 * keypad.c
 *
 *  Created on: Apr 27, 2022
 *      Author: Basel Ashraf
 */

#include "keypad.h"

#if(KEYPAD_COL == 4)
static uint8 keypad_4x4(uint8 buttonNumber);
#elif(KEYPAD_COL == 3)
static uint8 keypad_4x3(uint8 buttonNumber);
#endif
uint8 KeyPad_getPressedKey(void)
{

	while(1)
	{
		uint8 col = 0;
		while(col < KEYPAD_COL)
		{
			uint8 row = 0;
			/* Every column get to be output once per full loop to clear it so it can output
			   zero volts so the switch can put zero volt on its row line(pull up resistor by default)
			   and rows are configured as inputs */
			KEYPAD_PORT_DIR =   (0b00010000 << col );

			/* configure inputs as pull up resistors and output pin as zero volt pin*/
			KEYPAD_PORT_OUT = (~(0b00010000 << col ));

			while(row < KEYPAD_ROW)
			{
				if(BIT_IS_CLEAR(KEYPAD_PORT_IN , row))
				{
#if(KEYPAD_COL == 4)
				return keypad_4x4((row*KEYPAD_COL)+col+1);
#elif(KEYPAD_COL == 3)
				return keypad_4x3((row*KEYPAD_COL)+col+1);
#endif
				}

				row++;
			}

			col++;


		}
	}
}

#if (KEYPAD_COL == 3)

static uint8 keypad_4x3(uint8 buttonNumber)
{
	switch(buttonNumber)
	{
		case 10: return '*'; // ASCII Code of *
				 break;
		case 11: return 0;
				 break;
		case 12: return '#'; // ASCII Code of #
				 break;
		default: return buttonNumber;
	}
}

#elif (KEYPAD_COL == 4)

static uint8 keypad_4x4(uint8 buttonNumber)
{
	switch(buttonNumber)
	{
		case 1: return 7;
				break;
		case 2: return 8;
				break;
		case 3: return 9;
				break;
		case 4: return '%'; // ASCII Code of %
				break;
		case 5: return 4;
				break;
		case 6: return 5;
				break;
		case 7: return 6;
				break;
		case 8: return '*'; /* ASCII Code of '*' */
				break;
		case 9: return 1;
				break;
		case 10: return 2;
				break;
		case 11: return 3;
				break;
		case 12: return '-'; /* ASCII Code of '-' */
				break;
		case 13: return 13;  /* ASCII of Enter */
				break;
		case 14: return 0;
				break;
		case 15: return '='; /* ASCII Code of '=' */
				break;
		case 16: return '+'; /* ASCII Code of '+' */
				break;
		default: return buttonNumber;
	}
}

#endif

