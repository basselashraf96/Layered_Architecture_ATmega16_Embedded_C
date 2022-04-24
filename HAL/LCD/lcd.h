/*
 * lcd.h
 *
 *  Created on: Apr 21, 2022
 *      Author: Basel Ashraf
 */

#ifndef HAL_LCD_H_
#define HAL_LCD_H_

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_REG.h"
#include "../../UTILS/std_types.h"

/***************************************************
 * 			     MACROS					   *
 **************************************************/
#define LCD_BIT_MODE 8


/***************************************************
 * 			     PREPROCESSORS					   *
 **************************************************/


#define RS	dio_pin_rb0
#define RW	dio_pin_rb1
#define E   dio_pin_rb2

#define LCD_DATA_PORT_DIR DDRC
#define LCD_DATA_PORT PORTC


/***************************************************
 * 				LCD COMMANDS					   *
 **************************************************/

#define CLR_LCD        0x01
#define MOVE_CURSOR_RT 0x14
#define MOVE_CURSOR_LT 0x10
#define SHIFT_ALL_RT   0x1C
#define SHIFT_ALL_LT   0x18
#define CURSOR_BLINK   0x0F
#define CURSOR_OFF     0x0C
#define CURSOR_ON      0x0E
#define DSP_CURSOR_OFF 0x08
#define ENTRY_MODE     0x06
#define SET_CURSOR_POS 0x80
#if (LCD_BIT_MODE == 8)

#define ONE_LINE 0x30
#define TWO_LINE 0x38

#elif (LCD_BIT_MODE == 4)

#define ONE_LINE 0x20
#define TWO_LINE 0x28

#endif



/***************************************************
 * 			    FUNCTION PROTOTYPE				   *
 **************************************************/
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const char *Str);
void LCD_init(void);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_goToRowColumn(uint8 row,uint8 col);
void LCD_intgerToString(int data);

#endif /* HAL_LCD_H_ */
