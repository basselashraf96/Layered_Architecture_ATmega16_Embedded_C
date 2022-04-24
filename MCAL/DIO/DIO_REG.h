/*
 * DIO_REG.h
 *
 *  Created on: Apr 17, 2022
 *      Author: Basel Ashraf
 */

#ifndef MCAL_DIO_DIO_REG_H_
#define MCAL_DIO_DIO_REG_H_

#include "../../UTILS/std_types.h"


#define DDRA  (*(volatile uint8*)0x3A)
#define PORTA (*(volatile uint8*)0x3B)
#define PINA  (*(volatile uint8*)0x39)

#define DDRB  (*(volatile uint8*)0x37)
#define PORTB (*(volatile uint8*)0x38)
#define PINB  (*(volatile uint8*)0x36)

#define DDRC  (*(volatile uint8*)0x34)
#define PORTC (*(volatile uint8*)0x35)
#define PINC  (*(volatile uint8*)0x33)

#define DDRD  (*(volatile uint8*)0x32)
#define PORTD (*(volatile uint8*)0x31)
#define PIND  (*(volatile uint8*)0x30)

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6
#define PC7 7

#define PD0 0
#define PD1 1
#define PD2 2
#define PD3 3
#define PD4 4
#define PD5 5
#define PD6 6
#define PD7 7



#endif /* MCAL_DIO_DIO_REG_H_ */
