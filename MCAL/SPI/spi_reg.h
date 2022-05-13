/*
 * spi.reg.h
 *
 *  Created on: May 13, 2022
 *      Author: Basel Ashraf
 */

#ifndef MCAL_SPI_SPI_REG_H_
#define MCAL_SPI_SPI_REG_H_

#include "../../UTILS/std_types.h"

/***** Status Register (i-bit --> bit 7 ******/

#define SREG  (*(volatile uint8*)0x5F)

/*********************************************/
/********* SPI Control Register **************/

#define SPCR (*(volatile uint8*)0x2D)

#define SPIE 7 /* SPI Interrupt Enable       */
#define SPE  6 /* SPI Enable                 */
#define DORD 5 /* Data Order                 */
#define MSTR 4 /* MSTR: Master/Slave Select  */

/*********************************************/

/********* SPI Status Register ***************/

#define SPSR (*(volatile uint8*)0x2E)

#define SPIF  7  /* SPIF: SPI Interrupt Flag */
#define WCOL  6  /* Write COLlision flag     */
#define SPI2X 0  /* Double SPI Speed Bit     */

/********************************************/

/********* SPI Data Register ****************/

#define SPDR (*(volatile uint8*)0x2F)

/********************************************/

#endif /* MCAL_SPI_SPI_REG_H_ */
