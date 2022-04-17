/*
 * dio_test.c
 *
 *  Created on: Apr 17, 2022
 *      Author: Basel Ashraf
 */

#define F_CPU 1000000UL
#include "../../MCAL/DIO/DIO.h"
#include "util/delay.h"

int dio_app(void)
{
	set_pin_dir(dio_pin_ra0 , output);
	set_pin_state(dio_pin_ra0 , low);
	while(1)
	{
		set_pin_state(dio_pin_ra0 , high);
		_delay_ms(500);
		set_pin_state(dio_pin_ra0 , low);
		_delay_ms(500);

	}
	return 0;
}
