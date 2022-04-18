/*
 * timer.h
 *
 *  Created on: Apr 18, 2022
 *      Author: Basel Ashraf
 */

#ifndef MCAL_TIMER_0_TIMER0_H_
#define MCAL_TIMER_0_TIMER0_H_

#include "../../UTILS/std_types.h"



/*************************************************************************************
 	 	 	 	 	 *			MACROS			*
/*************************************************************************************/
//#define PWM_ACTIVE 				/* uncomment if you choose pwm mode */
//#define INTERRUPT_ACTIVE 			/* uncomment if you want to enable interrupt */


/*************************************************************************************
  	  	  	  	  *			Types Declaration			*
/*************************************************************************************/
typedef enum
{
	NORMAL , PWM , CTC , FAST_PWM,
}waveFormMode_t;

#ifndef PWM_ACTIVE
typedef enum
{
	OC0_DISCONNECTED , OC0_TOGGLE , OC0_CLEAR , OC0_SET
}compareOutputMode_t;
#else
typedef enum
{
	OC0_DISCONNECTED , RESERVED , OC0_CLEAR , OC0_SET
}compareOutputMode_t;
#endif

typedef enum
{
	NO_CLK , F_CPU_8 , F_CPU_64 , F_CPU_256 , F_CPU_1024 , EXTERNAL_CLK_FALLING , EXTERNAL_CLK_RISING,
}clk_select_t;

#ifdef INTERRUPT_ACTIVE
typedef enum
{
	COMPARE_MATCH_INTERRUPT , OVF_INTERRUPT,
}interruptType_t;
#endif

typedef struct
{
	waveFormMode_t waveFormMOde;
	compareOutputMode_t compareOutputMode;
	clk_select_t clk_select;

#ifdef INTERRUPT_ACTIVE
	interruptType_t interruptType;
#endif
}timer0_config_t;


/*************************************************************************************
  	  	  	  	  	  *			Function Prototypes			*
/*************************************************************************************/



#endif /* MCAL_TIMER_0_TIMER0_H_ */
