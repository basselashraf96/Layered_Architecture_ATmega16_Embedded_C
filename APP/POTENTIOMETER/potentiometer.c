/*
 * potentiometer.c
 *
 *  Created on: Apr 19, 2022
 *      Author: Basel Ashraf
 */


#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/ADC/adc.h"

#ifdef ADC_INTERRUPT_ENABLE
extern uint16 g_adc_result;
#endif

void potentiometer_app(void)
{
	set_pin_dir(dio_pin_rb0 , output);
	adc_config_t config = {ADC_AREF , ADC_FCPU_8 , Free_Running_mode};
	adc_init(&config);

	while(1)
	{

		if(adc_readChannel(0) > 512)
		{
			set_pin_state(dio_pin_rb0 , low);
		}
		else
		{
			set_pin_state(dio_pin_rb0 , high);
		}
	}
}
