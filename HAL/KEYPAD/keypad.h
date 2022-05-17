/*
 * keypad.h
 *
 *  Created on: Apr 27, 2022
 *      Author: Basel Ashraf
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include "../../MCAL/DIO/DIO_REG.h"
#include "../../UTILS/std_types.h"
#include "../../UTILS/common_macros.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define KEYPAD_ROW 4
#define KEYPAD_COL 4

/* Keypad Port Configurations */
#define KEYPAD_PORT_DIR DDRA
#define KEYPAD_PORT_OUT PORTA
#define KEYPAD_PORT_IN  PINA

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Function responsible for getting the pressed keypad key
 */
uint8 KeyPad_getPressedKey(void);


#endif /* HAL_KEYPAD_KEYPAD_H_ */
