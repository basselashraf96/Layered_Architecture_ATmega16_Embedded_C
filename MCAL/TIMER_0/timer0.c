/*
 * timer.c
 *
 *  Created on: Apr 18, 2022
 *      Author: Basel Ashraf
 */

#include "timer0.h"
#include "timer0_reg.h"
#include "../../UTILS/common_macros.h"

/**************************************************
 * 				Global Variables                  *
 **************************************************/
static volatile void(*g_callbackPtr)(void) = NULL_PTR;



/**************************************************
 * 				Interrupt Service Routine            *
 **************************************************/
#ifdef OVF_ACTIVE
ISR(TIMER0_OVF_vect)
{
	if(g_callbackPtr != NULL_PTR)
	{
		(*g_callbackPtr)();
	}
}
#else
ISR(TIMER0_COMP_vect)
{
	if(g_callbackPtr != NULL_PTR)
	{
		(*g_callbackPtr)();
	}
}
#endif



/**************************************************
 * 				Function Definition                 *
 **************************************************/

void timer0_init(const timer0_config_t* configPtr)
{
#ifdef INTERRUPT_ACTIVE
	SET_BIT(SREG , 7); /*enable I-bit to enable interrupt */
#endif

#ifndef PWM_ACTIVE
	SET_BIT(TCCR0 , FOC0); 			/* Force Output Compare  Bit-->7 */
#endif


	/*takes WGM00 and shift to bit 6 0b0000000X --> 0b0X000000    |    takes WGM01 and shift to bit 3 0b000000X0 --> 0b0000X000*/
	TCCR0 = (TCCR0 & 0xB7) | (((configPtr->waveFormMode & 0x01)<<6) | (configPtr->waveFormMode & 0x02)<<2);

	TCCR0 = (TCCR0 & 0xCF) | (configPtr->compareOutputMode << 4);

	TCCR0 = (TCCR0 & 0xF8) | (configPtr->clk_select);




}
void timer0_start(const timer0_config_t* configPtr , uint8 startVal , uint8 compareVal)
{
	uint8 garbage =0;
	TCNT0 = startVal;
	garbage = compareVal;
	TCCR0 = (TCCR0 & 0xF8) | (configPtr->clk_select);
#ifdef OVF_ACTIVE
	SET_BIT(TIMSK , TOIE0);


#else
	SET_BIT(TIMSK , OCIE0);
	TCNT0 = startVal;
	OCR0 = compareVal;
#endif



}
void timer0_stop(void)
{
	/* stop clock source */
	TCCR0 &= (~((1<<CS00)|(1<<CS01)|(1<<CS02)));
}


void timer0_setCallBack(void(*a_ptr)(void))
{
	g_callbackPtr = a_ptr;
}
