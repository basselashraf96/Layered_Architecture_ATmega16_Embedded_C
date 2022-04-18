/*
 * timer_reg.h
 *
 *  Created on: Apr 18, 2022
 *      Author: Basel Ashraf
 */

#ifndef MCAL_TIMER_0_TIMER0_REG_H_
#define MCAL_TIMER_0_TIMER0_REG_H_

#include "../../UTILS/std_types.h"



#define TCCR0 (*(volatile uint8*)0x53) /* Timer/Counter Control Register – TCCR0 */
#define TCNT0 (*(volatile uint8*)0x52) /* Timer/Counter0 (8 Bits) */
#define OCR0  (*(volatile uint8*)0x5C) /* Timer/Counter0 Output Compare Register */
#define TIMSK (*(volatile uint8*)0x59) /* Timer/Counter Interrupt Mask Register – TIMSK */
#define TIFR  (*(volatile uint8*)0x58) /* Timer/Counter Interrupt Flag Register – TIFR */
#define SFIOR (*(volatile uint8*)0x50) /* Special Function IO Register – SFIOR */

#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0  7



#endif /* MCAL_TIMER_0_TIMER0_REG_H_ */
