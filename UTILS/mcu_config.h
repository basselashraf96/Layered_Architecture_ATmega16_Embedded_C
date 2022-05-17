/*
 * mcu_config.h
 *
 *  Created on: May 17, 2022
 *      Author: Basel Ashraf
 */

#ifndef UTILS_MCU_CONFIG_H_
#define UTILS_MCU_CONFIG_H_


#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif

#include <avr/interrupt.h>
#include <util/delay.h>

#endif /* UTILS_MCU_CONFIG_H_ */
