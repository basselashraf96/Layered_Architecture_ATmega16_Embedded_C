/*
 * DIO.h
 *
 *  Created on: Apr 17, 2022
 *      Author: Basel Ashraf
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include "../../UTILS/std_types.h"


/*************************************************************************************
  	  	  	  	  *			Types Declaration			*
/*************************************************************************************/
typedef enum	//accomplished by this equation (pinNum = dio_pins_t % portSize) (pinNum is from 0 --> 7 always)
{
	dio_pin_ra0,
	dio_pin_ra1,
	dio_pin_ra2,
	dio_pin_ra3,
	dio_pin_ra4,
	dio_pin_ra5,
	dio_pin_ra6,
	dio_pin_ra7,

	dio_pin_rb0 = 8, // 8%portSize = 0  (portSize is 8 in atmega16)
	dio_pin_rb1,	 // 9%portSize = 1 and so on.
	dio_pin_rb2,
	dio_pin_rb3,
	dio_pin_rb4,
	dio_pin_rb5,
	dio_pin_rb6,
	dio_pin_rb7,

	dio_pin_rc0 = 16, //16%portSize = 0
	dio_pin_rc1,
	dio_pin_rc2,
	dio_pin_rc3,
	dio_pin_rc4,
	dio_pin_rc5,
	dio_pin_rc6,
	dio_pin_rc7,

	dio_pin_rd0 = 32, //32%portSize = 0
	dio_pin_rd1,
	dio_pin_rd2,
	dio_pin_rd3,
	dio_pin_rd4,
	dio_pin_rd5,
	dio_pin_rd6,
	dio_pin_rd7,


}dio_pins_t;

typedef enum	//accomplished by this equation (PORT required = pin / portSize) note:pin from 0 --> 39 in dio_pins_t
{
	dio_porta,  // pin<8 is portA
	dio_portb,	// pin<16 is PORTB
	dio_portc,	//pin<32 is PORTC
	dio_portd,	//pin>=32 is PORTD
}dio_port_t;

typedef enum
{
	input,
	output,
	internal_pullup
}dio_pin_dir_t;

typedef enum
{
	low,
	high,
}dio_pin_state_t;

/*************************************************************************************
  	  	  	  	  	  *			Function Prototypes			*
/*************************************************************************************/
void set_pin_dir(dio_pins_t pin , dio_pin_dir_t direction);
void set_pin_state(dio_pins_t pin , dio_pin_state_t state);
dio_pin_state_t read_pin(dio_pins_t pin);
void set_port_dir(dio_port_t port , uint8 direction);
void set_port_state(dio_port_t port , uint8 state);



#endif /* MCAL_DIO_DIO_H_ */
