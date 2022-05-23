/*
 * i2c.h
 *
 *  Created on: May 15, 2022
 *      Author: Basel Ashraf
 */

#ifndef MCAL_I2C_I2C_H_
#define MCAL_I2C_I2C_H_

#include "i2c_reg.h"
#include "../../UTILS/common_macros.h"
#include "../../UTILS/mcu_config.h"
#include "../../UTILS/std_types.h"

/***********************************************************************************
 *                        Configurations                                           *
 **********************************************************************************/
/* Uncomment and edit for desired MCU clock Frequency */

//#define F_CPU 8000000

/* Uncomment to select speed mode(only 1 can be active) */

#define I2C_SCL 50 /* choose between (50 , 100 , 400) kbps */

/* Add your device address(must be Unique #warning let bit 0 always 0
 * See TWAR register bit 0                                           */
#define TWI_OWN_ADDRESS 0x06

/* Configure device either Master or Slave */
#define TWI_SLAVE_MODE  0
#define TWI_MASTER_MODE 1
#define TWI_OPERATING_MODE TWI_MASTER_MODE

/***********************************************************************************
 *                      Preprocessor Macros                                      *
 **********************************************************************************/

/* I2C Status Bits(Master Transmit) in the TWSR Register (values in page 182 ATmega16 data sheet)  */

#define TW_START         0x08 /* start has been sent */
#define TW_REP_START     0x10 /* repeated start */
#define TW_MT_SLA_W_ACK  0x18 /* Master transmit ( slave address + Write request ) to slave + ACK received from slave */
#define TW_MT_SLA_R_ACK  0x40 /* Master transmit ( slave address + Read request ) to slave + ACK received from slave */
#define TW_MT_DATA_ACK   0x28 /* Master transmit data and ACK has been received from Slave */
#define TW_MR_DATA_ACK   0x50 /* Master received data and send ACK to slave */
#define TW_MR_DATA_NACK  0x58 /* Master received data but doesn't send ACK to slave */

/* I2C Status Bits(Slave Receive) in the TWSR Register (values in page 188 ATmega16 data sheet)  */

#define TW_SR_SLA_W_ACK  0x60 /* Slave Receive ( slave address + Write request ) + ACK has been returned */
#define TW_SR_DATA_ACK   0x80 /* Slave Received (data received) + ACK has been returned */

/***********************************************************************************
 *                      Functions Prototypes                                     *
 **********************************************************************************/

void TWI_init(void);

#if(TWI_OPERATING_MODE == TWI_MASTER_MODE)

void TWI_start(void);
void TWI_stop(void);
void TWI_write(uint8 data);
uint8 TWI_readWithACK(void); //read with send Ack
uint8 TWI_readWithNACK(void); //read without send Ack
uint8 TWI_sendByte(uint8 address , uint8 data);

#elif(TWI_OPERATING_MODE == TWI_SLAVE_MODE)

void TWI_match_read_slave(void);
uint8 TWI_read_slave(void);
uint8 TWI_slave_receive_byte(void);

#endif

uint8 TWI_getStatus(void);
#endif /* MCAL_I2C_I2C_H_ */
