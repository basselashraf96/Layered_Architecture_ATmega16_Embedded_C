/*
 * button_led_control.c
 *
 *  Created on: Apr 17, 2022
 *      Author: Basel Ashraf
 */



#include "../../MCAL/DIO/DIO.h"
#include "../../UTILS/mcu_config.h"

void control_led(void)
{
	set_pin_dir(dio_pin_rb0 , input);
	set_pin_dir(dio_pin_ra0 , output);
	set_pin_state(dio_pin_ra0 , low);

	while(1)
	{
		while(read_pin(dio_pin_rb0) == high)
		{
			_delay_ms(2); //debouncing
			while(read_pin(dio_pin_rb0) == high)
			{
				set_pin_state(dio_pin_ra0 , high);
			}
		}

		set_pin_state(dio_pin_ra0 , low);
	}

}
