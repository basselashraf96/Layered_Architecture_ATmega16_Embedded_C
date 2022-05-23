/*
 * i2c_app.c
 *
 *  Created on: May 21, 2022
 *      Author: Basel Ashraf
 */

#include "../../MCAL/I2C/i2c.h"


int i2c_app_test(void)
{
	_delay_ms(50); /* wait for initializations */

	TWI_init();

	while(1)
	{
		TWI_sendByte(0x02 , 5);
		_delay_ms(8); /* wait for data to be sent */
		TWI_sendByte(0x02 , 6);
		_delay_ms(8);
	}
	return 0;
}
