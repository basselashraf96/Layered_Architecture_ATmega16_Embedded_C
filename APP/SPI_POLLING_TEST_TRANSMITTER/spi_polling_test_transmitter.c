/*
 * spi_polling_test_transmitter.c
 *
 *  Created on: May 13, 2022
 *      Author: Basel Ashraf
 */


#include "../../MCAL/SPI/spi.h"

int spi_polling_transmitter_test(void)
{
	spi_config_t spi_config = {SPI_SAMPLE_R_SETUP_F , SPI_F_CPU_64};
	SPI_initMaster(&spi_config);
	SPI_sendByte(5);
	while(1)
	{

	}

	return 0;
}
