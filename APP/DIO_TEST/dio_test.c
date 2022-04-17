/*
 * dio_test.c
 *
 *  Created on: Apr 17, 2022
 *      Author: Basel Ashraf
 */


#include "../../MCAL/DIO/DIO.h"

int dio_app(void)
{
	set_pin_dir(dio_pin_ra0 , output);
	set_pin_state(dio_pin_ra0 , low);
	while(1)
	{
		set_pin_state(dio_pin_ra0 , high);
	}
	return 0;
}
