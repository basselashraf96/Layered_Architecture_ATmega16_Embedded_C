/*
 * spi.h
 *
 *  Created on: May 13, 2022
 *      Author: Basel Ashraf
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include "spi_reg.h"
#include "../../UTILS/common_macros.h"
#include "../DIO/DIO.h"
#include <avr/interrupt.h>
/************************************
 * 			CONFIGURATIONS
 *************************************/

#define SPI_MSB 0
#define SPI_LSB 1
#define SPI_DATA_ORDER   SPI_MSB       /* Select which bit is transfered first LSB or MSB */

#define SPI_INTERRUPT    ENABLE        /* Select between ENABLE and DISABLE               */

#define SPI_ENABLE	     ENABLE        /* Select between ENABLE and DISABLE               */

#define SPI_SLAVE_MODE  0
#define SPI_MASTER_MODE 1
#define SPI_MODE     SPI_MASTER_MODE   /* Select between master and slave mode            */

#define SPI_DOUBLE_SPEED_MODE  ENABLE  /* Select between ENABLE and DISABLE               */

/************************************
 * 			Types Declaration
 *************************************/

typedef enum
{
	SPI_SAMPLE_R_SETUP_F , SPI_SETUP_R_SAMPLE_F , SPI_SAMPLE_F_SETUP_R , SPI_SETUP_F_SAMPLE_R
}spi_clk_polarity_phase_mode_t;

#if(SPI_DOUBLE_SPEED_MODE == ENABLE)

typedef enum
{
	SPI_F_CPU_2 , SPI_F_CPU_8 , SPI_F_CPU_32 , SPI_F_CPU_64
}spi_clk_rate_t;

#else

typedef enum
{
	SPI_F_CPU_4 , SPI_F_CPU_16 , SPI_F_CPU_64 , SPI_F_CPU_128
}spi_clk_rate_t;

#endif

typedef struct
{
	spi_clk_polarity_phase_mode_t spi_clk_polarity_phase_mode;
	spi_clk_rate_t spi_clk_rate;
}spi_config_t;

/************************************
 * 			Function Prototype
 *************************************/
#if(SPI_MODE == SPI_MASTER_MODE)

void SPI_initMaster(spi_config_t* config);

#else

void SPI_initSlave(spi_config_t* config);

#endif

void SPI_sendByte(const uint8 data);
uint8 SPI_recieveByte(void);
void SPI_sendString(const uint8 *Str);
void SPI_receiveString(char *Str);

#if(SPI_INTERRUPT == ENABLE)

void SPI_setCallBack(void(*a_ptr)(void));

#endif
#endif /* MCAL_SPI_SPI_H_ */
