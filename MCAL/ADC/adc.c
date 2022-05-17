/*
 * adc.c
 *
 *  Created on: Apr 19, 2022
 *      Author: Basel Ashraf
 */

/************************************************************
 * 			Register addresses ATmega16 data sheet Page(298)
 * 			Register Description Page(211)
 ************************************************************/
#include "adc.h"

/************************************************************
 * 					Global Variables
 ************************************************************/
#ifdef ADC_INTERRUPT_ENABLE

volatile uint16 g_adc_result = 0;

#endif
/************************************************************
 * 				INTERRUPT SERVICE ROUTINE
 ************************************************************/
#ifdef ADC_INTERRUPT_ENABLE
ISR(ADC_vect)
{
	g_adc_result = ADC;
}
#endif



void adc_init(adc_config_t* config)
{
	ADMUX = 0; /* channel 0 as initialization MUX4:0 = 0000 */

	ADMUX  = (ADMUX  & 0x3F)   | (config->adc_reference_Selection_Bits <<6);
	ADCSRA = (ADCSRA & 0xF8)   | (config->adc_prescaler_selection);
	SFIOR  = (SFIOR  & 0x1F)   | (config->adc_Auto_Trigger_Source <<5);

	SET_BIT(ADCSRA , ADC_ENABLE);

#ifdef ADC_INTERRUPT_ENABLE

	SET_BIT(SREG , 7); /*enable I-bit to enable interrupt */
	SET_BIT(ADCSRA , ADC_Interrupt_Enable );

#endif

#ifdef ADC_HIGH_SPEED_MODE

	SET_BIT(SFIOR , ADC_High_Speed_Mode); /*enable I-bit to enable interrupt */

#endif
}


uint16 adc_readChannel(uint8 channel)
{
	channel &= 0x07; 		 /* Channel must be from between 0 --> 7 */
	ADMUX &= 0xE0;	 		 /* clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel; /* choose the correct channel by setting the channel number in MUX4:0 bits */

	SET_BIT(ADCSRA , ADC_Start_Conversion);

#ifndef ADC_INTERRUPT_ENABLE
	while(BIT_IS_CLEAR(ADCSRA , ADC_Interrupt_Flag )); /* (POLLING) wait until conversion is complete */
	SET_BIT(ADCSRA , ADC_Interrupt_Flag); /* clear flag by writing 1*/
	return ADC;
#else
	return 0;
#endif
}


