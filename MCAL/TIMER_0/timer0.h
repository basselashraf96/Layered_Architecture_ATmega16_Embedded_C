/*
 * timer.h
 *
 *  Created on: Apr 18, 2022
 *      Author: Basel Ashraf
 */

#ifndef MCAL_TIMER_0_TIMER0_H_
#define MCAL_TIMER_0_TIMER0_H_

#include "../../UTILS/std_types.h"
#include <avr/interrupt.h>



/*************************************************************************************
 	 	 	 	 	 *			MACROS			*
***********************************************************************************/
//#define PWM_ACTIVE 				/* uncomment PWM_ACTIVE to activate pwm mode */
#define INTERRUPT_ACTIVE 			/* uncomment INTERRUPT_ACTIVE to activate interrupt */
#define OVF_ACTIVE				    /* uncomment OVF_ACTIVE	to activate overflow and deactivate compare mode */

#define CTC_ACTIVE

#ifdef OVF_ACTIVE
#undef CTC_ACTIVE
#endif


/*************************************************************************************
  	  	  	  	  *			Types Declaration			*
************************************************************************************/
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
	NO_CLK ,FCPU, F_CPU_8 , F_CPU_64 , F_CPU_256 , F_CPU_1024 , EXTERNAL_CLK_FALLING , EXTERNAL_CLK_RISING,
}clk_select_t;

#ifdef INTERRUPT_ACTIVE
typedef enum
{
	COMPARE_MATCH_INTERRUPT , OVF_INTERRUPT,
}interruptType_t;
#endif

typedef struct
{
	waveFormMode_t waveFormMode;
	compareOutputMode_t compareOutputMode;
	clk_select_t clk_select;
}timer0_config_t;


/*************************************************************************************
  	  	  	  	  	  *			Function Prototypes			*
*************************************************************************************/
void timer0_init(const timer0_config_t* configPtr);
void timer0_start(const timer0_config_t* configPtr , uint8 startVal , uint8 compareVal);
void timer0_stop(void);
void timer0_setCallBack(void(*a_ptr)(void));



#endif /* MCAL_TIMER_0_TIMER0_H_ */
