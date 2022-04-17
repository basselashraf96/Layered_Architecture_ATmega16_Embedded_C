/*
 * DIO.c
 *
 *  Created on: Apr 17, 2022
 *      Author: Basel Ashraf
 */
#include "DIO.h"
#include "DIO_REG.h"
#include "../../UTILS/std_types.h"
#include "../../UTILS/common_macros.h"

#define PORT_SIZE 8

void set_pin_dir(dio_pins_t pin , dio_pin_dir_t direction)
{
	uint8 pinNum = pin%PORT_SIZE;
	dio_port_t port = pin/PORT_SIZE;
	switch(port)
	{
	case dio_porta:
		if(direction == input)
		{
			CLEAR_BIT(DDRA , pinNum);
		}
		else if(direction == output)
		{
			SET_BIT(DDRA , pinNum);
		}
		else if(direction == internal_pullup)
		{
			CLEAR_BIT(DDRA , pinNum);
			SET_BIT(PORTA , pinNum);
		}
		break;
	case dio_portb:
		if(direction == input)
		{
			CLEAR_BIT(DDRB , pinNum);
		}
		else if(direction == output)
		{
			SET_BIT(DDRB , pinNum);
		}
		else if(direction == internal_pullup)
		{
			CLEAR_BIT(DDRB , pinNum);
			SET_BIT(PORTB , pinNum);
		}
		break;
	case dio_portc:
		if(direction == input)
		{
			CLEAR_BIT(DDRC , pinNum);
		}
		else if(direction == output)
		{
			SET_BIT(DDRC , pinNum);
		}
		else if(direction == internal_pullup)
		{
			CLEAR_BIT(DDRC , pinNum);
			SET_BIT(PORTC , pinNum);
		}
		break;

	case dio_portd:
		if(direction == input)
		{
			CLEAR_BIT(DDRD , pinNum);
		}
		else if(direction == output)
		{
			SET_BIT(DDRD , pinNum);
		}
		else if(direction == internal_pullup)
		{
			CLEAR_BIT(DDRD , pinNum);
			SET_BIT(PORTD , pinNum);
		}
		break;

	default:
		break;
	}
}

void set_pin_state(dio_pins_t pin , dio_pin_state_t state)
{
	uint8 pinNum = pin%PORT_SIZE;
	dio_port_t port = pin/PORT_SIZE;
	switch(port)
	{
	case dio_porta:
		if(state == low)
		{
			CLEAR_BIT(PORTA , pinNum);
		}
		else if(state == high)
		{
			SET_BIT(PORTA , pinNum);
		}

		break;
	case dio_portb:
		if(state == low)
		{
			CLEAR_BIT(PORTB , pinNum);
		}
		else if(state == high)
		{
			SET_BIT(PORTB , pinNum);
		}

		break;
	case dio_portc:
		if(state == low)
		{
			CLEAR_BIT(PORTC , pinNum);
		}
		else if(state == high)
		{
			SET_BIT(PORTC , pinNum);
		}

		break;

	case dio_portd:
		if(state == low)
		{
			CLEAR_BIT(PORTD , pinNum);
		}
		else if(state == high)
		{
			SET_BIT(PORTD , pinNum);
		}
		break;

	default:
		break;
	}

}

dio_pin_state_t read_pin(dio_pins_t pin)
{
	uint8 pinNum = pin%PORT_SIZE;
	dio_port_t port = pin/PORT_SIZE;
	dio_pin_state_t bit_state = low;
	switch(port)
	{
	case dio_porta:
		bit_state = READ_BIT(PINA , pinNum);
		break;
	case dio_portb:
		bit_state = READ_BIT(PINB , pinNum);
		break;
	case dio_portc:
		bit_state = READ_BIT(PINC , pinNum);
		break;
	case dio_portd:
		bit_state = READ_BIT(PIND , pinNum);
		break;
	default:
		break;
	}
	return bit_state;
}

void set_port_dir(dio_port_t port , uint8 dir)
{

}

void set_port_state(dio_port_t port , uint8 state)

{

}
