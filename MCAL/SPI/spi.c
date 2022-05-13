/*
 * spi.c
 *
 *  Created on: May 13, 2022
 *      Author: Basel Ashraf
 */

#include "spi.h"
/*********************************************************
 * 				Global Variables
 *********************************************************/

static volatile void(*g_callbackPtr)(void) = NULL_PTR;

/*********************************************************
 * 			INTERRUPT SERVICE ROUTINE
 *********************************************************/
#if(SPI_INTERRUPT == ENABLE && SPI_MODE == SPI_MASTER_MODE)
ISR(SPI_STC_vect)
{
	if(g_callbackPtr != NULL_PTR)
	{
		(*g_callbackPtr)();
	}
}
#endif
/*********************************************************
 * 			FUNCTION DEFINITION
 *********************************************************/
#if(SPI_MODE == SPI_MASTER_MODE)

void SPI_initMaster(spi_config_t* config)
{
	set_pin_dir(dio_pin_rb4 , output); /* Slave Select -> output */
	set_pin_dir(dio_pin_rb5 , output); /* MOSI ---------> output */
	set_pin_dir(dio_pin_rb6 , input);  /* MISO  --------> input  */
	set_pin_dir(dio_pin_rb7 , output); /* SCLK  --------> output */

	SET_BIT(SPCR , MSTR); /* MSTR bit selects Master SPI mode when written to one */

#if(SPI_INTERRUPT == ENABLE)

	SET_BIT(SREG , 7);
	SET_BIT(SPCR , SPIE);

#elif(SPI_INTERRUPT == DISABLE)

	CLEAR_BIT(SPCR , SPIE);
	CLEAR_BIT(SREG , 7);

#endif

#if(SPI_DATA_ORDER == SPI_MSB)

	CLEAR_BIT(SPCR , DORD);

#elif(SPI_DATA_ORDER == SPI_LSB)

	SET_BIT(SPCR , DORD);

#endif

#if(SPI_DOUBLE_SPEED_MODE == ENABLE)

	SET_BIT(SPSR , SPI2X);
	SPCR = (SPCR & 0xFC) | (config->spi_clk_rate);

#elif(SPI_DOUBLE_SPEED_MODE == DISABLE)

	CLEAR_BIT(SPSR , SPI2X);
	SPCR = (SPCR & 0xFC) | (config->spi_clk_rate);

#endif

	SPCR = (SPCR & 0xF3) | (config->spi_clk_polarity_phase_mode << 2);

#if(SPI_ENABLE == ENABLE)

	SET_BIT(SPCR , SPE);

#elif(SPI_ENABLE == DISABLE)

	CLEAR_BIT(SPCR , SPE);

#endif

}

#elif(SPI_MODE == SPI_SLAVE_MODE)

void SPI_initSlave(spi_config_t* config)
{
	set_pin_dir(dio_pin_rb4 , input);  /* Slave Select -> input  */
	set_pin_dir(dio_pin_rb5 , input);  /* MOSI ---------> input  */
	set_pin_dir(dio_pin_rb6 , output); /* MISO  --------> output */
	set_pin_dir(dio_pin_rb7 , input);  /* SCLK  --------> input  */

	CLEAR_BIT(SPCR , MSTR); /* MSTR bit selects Slave SPI mode when written to zero */

#if(SPI_INTERRUPT == ENABLE)

	SET_BIT(SREG , 7);
	SET_BIT(SPCR , SPIE);

#elif(SPI_INTERRUPT == DISABLE)

	CLEAR_BIT(SPCR , SPIE);
	CLEAR_BIT(SREG , 7);

#endif

#if(SPI_DATA_ORDER == SPI_MSB)

	CLEAR_BIT(SPCR , DORD);

#elif(SPI_DATA_ORDER == SPI_LSB)

	SET_BIT(SPCR , DORD);

#endif

#if(SPI_DOUBLE_SPEED_MODE == ENABLE)

	SET_BIT(SPSR , SPI2X);
	SPCR = (SPCR & 0xFC) | (config->spi_clk_rate);

#elif(SPI_DOUBLE_SPEED_MODE == DISABLE)

	CLEAR_BIT(SPSR , SPI2X);
	SPCR = (SPCR & 0xFC) | (config->spi_clk_rate);

#endif

	SPCR = (SPCR & 0xF3) | (config->spi_clk_polarity_phase_mode << 2);

#if(SPI_ENABLE == ENABLE)

	SET_BIT(SPCR , SPE);

#elif(SPI_ENABLE == DISABLE)

	CLEAR_BIT(SPCR , SPE);

#endif

}

#endif

void SPI_sendByte(const uint8 data)
{
	SPDR = data;
	while(BIT_IS_CLEAR(SPSR , SPIF)){}
}
uint8 SPI_recieveByte(void)
{
	while(BIT_IS_CLEAR(SPSR , SPIF)){}
	return SPDR;
}
void SPI_sendString(const uint8 *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		SPI_sendByte(Str[i]);
		i++;
	}
}
void SPI_receiveString(char *Str)
{
	unsigned char i = 0;
	Str[i] = SPI_recieveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = SPI_recieveByte();
	}
	Str[i] = '\0';
}

#if(SPI_INTERRUPT == ENABLE)

void SPI_setCallBack(void(*a_ptr)(void))
{
	g_callbackPtr = a_ptr;
}

#endif
