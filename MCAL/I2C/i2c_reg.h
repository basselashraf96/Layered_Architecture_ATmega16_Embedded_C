/*
 * i2c_reg.h
 *
 *  Created on: May 15, 2022
 *      Author: Basel Ashraf
 */

#ifndef MCAL_I2C_I2C_REG_H_
#define MCAL_I2C_I2C_REG_H_

#include "../../UTILS/std_types.h"

/***** Status Register (i-bit --> bit 7 *****************************/

#define SREG  (*(volatile uint8*)0x5F)

/********************************************************************/

/********* Two-wire Serial Interface Bit Rate Register **************/

#define TWBR (*(volatile uint8*)0x20)

/********************************************************************/

/********* TWI Control Register *************************************/

#define TWCR (*(volatile uint8*)0x56)

#define TWINT 7 /* TWI Interrupt Flag         */
#define TWEA  6 /* TWI Enable Acknowledge Bit */
#define TWSTA 5 /* TWI START Condition Bit	  */
#define TWSTO 4 /* TWI STOP Condition Bit     */
#define TWWC  3 /* TWI Write Collision Flag   */
#define TWEN  2 /* TWI Enable Bit             */
#define TWIE  0 /* TWI Interrupt Enable       */


/********************************************************************/

/********* TWI Status Register **************************************/

#define TWSR (*(volatile uint8*)0x21)

/********************************************************************/

/********* TWI Data Register ****************************************/

#define TWDR (*(volatile uint8*)0x23)

/********************************************************************/

/********* TWI (Slave) Address Register *****************************/

#define TWAR (*(volatile uint8*)0x22)

#define TWGCE 0 /* TWI General Call Recognition Enable Bit */

/********************************************************************/


#endif /* MCAL_I2C_I2C_REG_H_ */
