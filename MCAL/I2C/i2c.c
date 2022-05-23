/*
 * i2c.c
 *
 *  Created on: May 15, 2022
 *      Author: Basel Ashraf
 */
#include "i2c.h"
#include "i2c_speed_modes.h"

void TWI_init(void)
{
#if(TWI_OPERATING_MODE == TWI_MASTER_MODE)
	/*   Select Speed from   */
	TWBR = I2C_SPEED_MODE;

	/*     TWPS = 00     */
	TWSR = 0;

	/* TWI Enable Bit    */
	SET_BIT(TWCR , TWEN);

#elif(TWI_OPERATING_MODE == TWI_SLAVE_MODE)

	/* my address = 0x01 */
	TWAR = TWI_OWN_ADDRESS;
	CLEAR_BIT(TWAR , 0); /* TWI General Call Recognition Enable Bit (off)  */

	/* TWI Enable Bit    */
	SET_BIT(TWCR , TWEA);
	SET_BIT(TWCR , TWEN);

#endif
}

#if(TWI_OPERATING_MODE == TWI_MASTER_MODE)
void TWI_start(void)
{
	/*
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	/* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
	while(BIT_IS_CLEAR(TWCR,TWINT)){}
}

void TWI_stop(void)
{
	/*
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void TWI_write(uint8 data)
{
	/* Put data On TWI data Register */
	TWDR = data;
	/*
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR = (1 << TWINT) | (1 << TWEN);
	/* Wait for TWINT flag set in TWCR Register(data is send successfully) */
	while(BIT_IS_CLEAR(TWCR,TWINT)){}

}

uint8 TWI_readWithACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	/* Wait for TWINT flag set in TWCR Register (data received successfully) */
	while(BIT_IS_CLEAR(TWCR,TWINT)){}
	/* Read Data */
	return TWDR;
}

uint8 TWI_readWithNACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
	TWCR = (1 << TWINT) | (1 << TWEN);
	/* Wait for TWINT flag set in TWCR Register (data received successfully) */
	while(BIT_IS_CLEAR(TWCR,TWINT)){}
	/* Read Data */
	return TWDR;
}

uint8 TWI_sendByte(uint8 address , uint8 data)
{

	TWI_start();
	if (TWI_getStatus() != TW_START)
		return ERROR;

	TWI_write(address);
	if (TWI_getStatus() != TW_MT_SLA_W_ACK)
		return ERROR;

	TWI_write(data);

	if (TWI_getStatus() != TW_MT_DATA_ACK)
		return ERROR;

	TWI_stop();

	return SUCCESS;
}


#elif(TWI_OPERATING_MODE == TWI_SLAVE_MODE)

void TWI_match_read_slave(void)
{
	while(TWI_getStatus() != TW_SR_SLA_W_ACK)
	{
		/* Get ACK, Enable TWI, Clear TWI interrupt flag */
		TWCR=(1<<TWEA)|(1<<TWEN)|(1<<TWINT);
		while (!(TWCR & (1<<TWINT))){}  // Wait for TWINT flag
	}
}

uint8 TWI_read_slave(void)
{
	TWCR= (1<<TWINT)|(1<<TWEA)|(1<<TWEN);

	while(BIT_IS_CLEAR(TWCR , TWINT)){}
	while(TWI_getStatus() != TW_SR_DATA_ACK){} /* Wait for acknowledgement */

	return TWDR;
}

uint8 TWI_slave_receive_byte(void)
{
	TWI_match_read_slave();   /* Receive own address and return ACK to master */
	return TWI_read_slave();  /* Receive byte from master */
}

#endif

uint8 TWI_getStatus(void)
{
	uint8 status;
	/* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
	status = TWSR & 0xF8;
	return status;
}
