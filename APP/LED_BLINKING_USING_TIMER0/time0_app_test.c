/*
 * time0_app_test.c
 *
 *  Created on: Apr 18, 2022
 *      Author: Basel Ashraf
 */

#include "../../MCAL/TIMER_0/timer0.h"
#include "../../MCAL/DIO/DIO.h"

uint8 tick = 0;

void blinking_app(void)
{
	tick++;
	if(tick == 4)
	{
		set_pin_state(dio_pin_ra0 , high);

	}
	if(tick == 8)
	{
		set_pin_state(dio_pin_ra0 , low);
		tick = 0;

	}
}

int timer0_app(void)
{
	set_pin_dir(dio_pin_ra0 , output);
	set_pin_state(dio_pin_ra0 , low);

	timer0_config_t config = {TIMER0_FAST_PWM , OC0_CLEAR , TIMER0_F_CPU_8};
	timer0_setCallBack(blinking_app);
	timer0_init(&config);

	timer0_start(&config , 0 , 64);
	while(1)
	{

	}


	return 0;
}
