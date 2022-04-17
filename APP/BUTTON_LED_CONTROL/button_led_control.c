/*
 * button_led_control.c
 *
 *  Created on: Apr 17, 2022
 *      Author: Basel Ashraf
 */


#define F_CPU 1000000UL
#include "../../MCAL/DIO/DIO.h"
#include "util/delay.h"

void control_led(void)
{
	set_pin_dir(dio_pin_rb0 , input);
	set_pin_dir(dio_pin_ra0 , output);
	set_pin_state(dio_pin_ra0 , low);

	while(1)
	{
		while(read_pin(dio_pin_rb0) == high)
		{
			_delay_ms(2);
			while(read_pin(dio_pin_rb0) == high)
			{
				set_pin_state(dio_pin_ra0 , high);
			}
		}

		set_pin_state(dio_pin_ra0 , low);
	}

}
