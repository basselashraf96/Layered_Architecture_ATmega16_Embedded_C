/*
 * lcd.c
 *
 *  Created on: Apr 21, 2022
 *      Author: Basel Ashraf
 */


#include "lcd.h"
#include <util/delay.h>

/* waiting values from LCD data sheet (LMB162ABC) */

void LCD_sendCommand(uint8 command)
{
	set_pin_state(RS , low);
	set_pin_state(RW , low);
	_delay_ms(1); /* wait for tas Duration minimum 50 ns */
	set_pin_state(E , high);
	_delay_ms(1); /* wait for (tpw - tdsw) Duration minimum 190 ns */
	LCD_DATA_PORT = command;
	_delay_ms(1); /* wait for (tdsw) Duration minimum 100 ns */
	set_pin_state(E , low);
	_delay_ms(1); /* wait for (th) Duration minimum 13 ns */
}

void LCD_displayCharacter(uint8 data)
{
	set_pin_state(RS , high);
	set_pin_state(RW , low);
	_delay_ms(1); /* wait for tas Duration minimum 50 ns */
	set_pin_state(E , high);
	_delay_ms(1); /* wait for (tpw - tdsw) Duration minimum 190 ns */
	LCD_DATA_PORT = data;
	_delay_ms(1); /* wait for (tdsw) Duration minimum 100 ns */
	set_pin_state(E , low);
	_delay_ms(1); /* wait for (th) Duration minimum 13 ns */
}
void LCD_displayString(const char *Str)
{
	uint8 counter  = 0;

	while(Str[counter] != '\0')
	{
		LCD_displayCharacter(Str[counter]);
		counter++;
	}

}

void LCD_init(void)
{
	LCD_DATA_PORT_DIR = 0xFF;

	set_pin_dir(RS , output);
	set_pin_dir(E , output);
	set_pin_dir(RW , output);

	LCD_sendCommand(TWO_LINE);
	LCD_sendCommand(CURSOR_OFF);
	LCD_sendCommand(CLR_LCD);

}
void LCD_clearScreen(void)
{
	LCD_sendCommand(CLR_LCD);
}
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_goToRowColumn(row , col);
	LCD_displayString(Str);

}
void LCD_goToRowColumn(uint8 row,uint8 col)
{
	uint8 address = 0;
	switch (row) {
	case 0:
		address = col;      //1st row
		break;
	case 1:
		address = col+0x40; //2nd row
		break;
	case 2:
		address = col+0x14; //3rd row
		break;
	case 3:
		address = col+0x54; //4th row
		break;
	default:
		break;
	}
	LCD_sendCommand(address | SET_CURSOR_POS); /* 0x80 + address* */
}
void LCD_intgerToString(int data)
{
	char buff[16]; /* String to hold the ascii result */
	itoa(data,buff,10); /* 10 for decimal */
	LCD_displayString(buff);
}
