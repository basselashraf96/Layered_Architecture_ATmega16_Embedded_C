/*
 * timer.c
 *
 *  Created on: Apr 18, 2022
 *      Author: Basel Ashraf
 */
#include "timer0.h"
#include "timer0_reg.h"
#include "../../UTILS/common_macros.h"

void timer0_init(const timer0_config_t* configPtr)
{


#ifndef PWM_ACTIVE
	SET_BIT(TCCR0 , FOC0); 			/* Force Output Compare  Bit-->7 */
#endif


			/*takes WGM00 and shift to bit 6 0b0000000X --> 0b0X000000    |    takes WGM01 and shift to bit 3 0b000000X0 --> 0b0000X000*/
	TCCR0 = (TCCR0 & 0xB7) | (((configPtr->waveFormMode & 0x01)<<6) | (configPtr->waveFormMode & 0x02)<<2);



}
void timer0_start(void)
{

}
void timer0_stop(void)
{

}
