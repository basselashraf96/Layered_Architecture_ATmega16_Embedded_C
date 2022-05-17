/*
 * adc.h
 *
 *  Created on: Apr 19, 2022
 *      Author: Basel Ashraf
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

/************************************************************
 * 			Register addresses ATmega16 data sheet Page(298)
 * 			Register Description Page(211)
 ************************************************************/
#include "adc_reg.h"
#include "../../UTILS/common_macros.h"
#include "../../UTILS/mcu_config.h"

/*******************************************************
 * 					Macros
 ******************************************************/

//#define ADC_INTERRUPT_ENABLE
//#define LEFT_ADJUSTED           /*If using left adjusted, reading ADCH is sufficient if 8-bit precision is only required. Otherwise, ADCL must be read first, then ADCH.*/
//#define ADC_HIGH_SPEED_MODE

/*******************************************************
 * 					Types Declaration
 ******************************************************/
/* AREF, Internal VREF turned off                                                        */
/* AVCC with external capacitor at AREF pin                                              */
/* INTERNAL_VREF is Internal 2.56V Voltage Reference with external capacitor at AREF pin */
typedef enum
{
	ADC_AREF, ADC_AVCC , ADC_RESERVED , ADC_INTERNAL_VREF,

}adc_reference_Selection_Bits_t;
typedef enum
{
	ADC_FCPU2, ADC_FCPU_2 , ADC_FCPU_4 , ADC_FCPU_8, ADC_FCPU_16 , ADC_FCPU_32 , ADC_FCPU_64 , ADC_FCPU_128 ,

}adc_prescaler_selection_t;

typedef enum
{
	Free_Running_mode,  Analog_Comparator , External_Interrupt_Request_0 ,Timer0_Compare_Match, Timer0_Overflow , Timer_Compare_Match_B , Timer1_overflow , Timer1_Capture_Event ,

}adc_Auto_Trigger_Source_t;

typedef struct
{
	adc_reference_Selection_Bits_t adc_reference_Selection_Bits;
	adc_prescaler_selection_t adc_prescaler_selection;
	adc_Auto_Trigger_Source_t adc_Auto_Trigger_Source;
}adc_config_t;


/*******************************************************
 * 					Function Prototype
 ******************************************************/
void adc_init(adc_config_t* config);
uint16 adc_readChannel(uint8 channel);


#endif /* MCAL_ADC_ADC_H_ */
