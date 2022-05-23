/*
 * i2c_speed_modes.h
 *
 *  Created on: May 17, 2022
 *      Author: Basel Ashraf
 */

#ifndef MCAL_I2C_I2C_SPEED_MODES_H_
#define MCAL_I2C_I2C_SPEED_MODES_H_

#include "i2c.h"

/* Uncomment and edit for desired MCU clock Frequency */

//#define F_CPU 8000000

/******** Uncomment to select speed mode(only 1 can be active) ********/

#if(I2C_SCL == 50) /* i2c speed mode is 50 kbps */

#elif(I2C_SCL == 100) /* i2c speed mode is 100 kbps */

#elif(I2C_SCL == 400) /* i2c speed mode is 400 kbps */

#endif
/**********************************************************************/
#if(F_CPU == 1000000UL && I2C_SCL == 50)

# define I2C_SPEED_MODE (uint8)0x02 /* Add this value to TWBR register to achieve required speed */

#elif(F_CPU == 2000000UL && I2C_SCL == 50)

# define I2C_SPEED_MODE (uint8)0x0C

#elif(F_CPU == 2000000UL && I2C_SCL == 100)

# define I2C_SPEED_MODE (uint8)0x02

#elif(F_CPU == 4000000UL && I2C_SCL == 100)

# define I2C_SPEED_MODE (uint8)0x0C

#elif(F_CPU == 8000000UL && I2C_SCL == 100)

# define I2C_SPEED_MODE (uint8)0x20

#elif(F_CPU == 8000000UL && I2C_SCL == 400)

# define I2C_SPEED_MODE (uint8)0x02

#elif(F_CPU == 12000000UL && I2C_SCL == 100)

# define I2C_SPEED_MODE (uint8)0x34

#elif(F_CPU == 12000000UL && I2C_SCL == 400)

# define I2C_SPEED_MODE (uint8)0x07

#elif(F_CPU == 16000000UL && I2C_SCL == 100)

# define I2C_SPEED_MODE (uint8)0x48

#elif(F_CPU == 16000000UL && I2C_SCL == 400)

# define I2C_SPEED_MODE (uint8)0x0C

#endif

/*************ERROR CHECKING*********************/

#if(I2C_SCL == 100 && F_CPU == 1000000UL)
# error "F_CPU  1Mhz only supports 50kbps"
#endif

#if(I2C_SCL == 400 && F_CPU == 1000000UL)
# error "F_CPU  1Mhz only supports 50kbps"
#endif

#if(I2C_SCL == 400 && F_CPU == 2000000UL)
# error "F_CPU  2Mhz only supports 50 and 100 kbps"
#endif

#if(I2C_SCL == 400 && F_CPU == 4000000UL)
# error "F_CPU 4Mhz only supports 100kbps"
#endif

#if(I2C_SCL == 50 && F_CPU == 4000000UL)
# error "F_CPU 4Mhz only supports 100kbps"
#endif

#if(I2C_SCL == 50 && F_CPU == 8000000UL)
# error "F_CPU 8Mhz does not supports 50kbps"
#endif

#if(I2C_SCL == 50 && F_CPU == 12000000UL)
# error "F_CPU 12Mhz does not supports 50kbps"
#endif

#if(I2C_SCL == 50 && F_CPU == 16000000UL)
# error "F_CPU 16Mhz does not supports 50kbps"
#endif
/**********************************************/
#endif /* MCAL_I2C_I2C_SPEED_MODES_H_ */
