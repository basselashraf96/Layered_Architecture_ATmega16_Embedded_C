/*
 * adc_reg.h
 *
 *  Created on: Apr 19, 2022
 *      Author: Basel Ashraf
 */

/************************************************************
 * 			Register addresses ATmega16 data sheet Page(298)
 * 			Register Description Page(211)
 ************************************************************/

#ifndef MCAL_ADC_ADC_REG_H_
#define MCAL_ADC_ADC_REG_H_

#include "../../UTILS/std_types.h"


#define SREG  (*(volatile uint8*)0x5F) /*Status Register (i-bit --> bit 7*/

#define ADMUX  (*(volatile uint8*)0x27)  /* ADC multiplexer selection register    */
#define ADCSRA (*(volatile uint8*)0x26)  /* ADC Control and Status Register A     */
#define ADC	   (*(volatile uint16*)0x24) /*           ADCL + ADCH                 */
#define ADCH   (*(volatile uint8*)0x25)	 /* The ADC Data Register – ADCL and ADCH */
#define ADCL   (*(volatile uint8*)0x24)	 /* The ADC Data Register – ADCL and ADCH */
#define SFIOR  (*(volatile uint8*)0x50)	 /* Special FunctionIO Register           */

/*********************************/
 	 /* 	ADCSRA Bits     */
#define ADC_Interrupt_Enable     3
#define ADC_Interrupt_Flag 		 4
#define ADC_Auto_Trigger_Enable  5
#define ADC_Start_Conversion 	 6
#define ADC_ENABLE               7
/**********************************/

#define ADC_High_Speed_Mode 4


#endif /* MCAL_ADC_ADC_REG_H_ */
