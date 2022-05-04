/*
 * uart_reg.h
 *
 *  Created on: Apr 30, 2022
 *      Author: Basel Ashraf
 */

#ifndef MCAL_UART_UART_REG_H_
#define MCAL_UART_UART_REG_H_

#include "../../UTILS/std_types.h"

/********************************************************
 * 			   Registers Addresses
 ********************************************************/
/*Control and Status Register A */
#define UCSRA (*(volatile uint8*)0x2B)

#define RXC 7    /* USART Receive Complete              */
#define TXC 6    /* USART Transmit Complete             */
#define UDRE 5   /* USART Data Register Empty           */
#define FE 4     /* Frame Error                         */
#define DOR 3    /* Data OverRun                        */
#define PE 2     /* Parity Error                        */
#define U2X 1    /* Double the USART Transmission Speed */
#define MPCM 0   /* Multi-processor Communication Mode  */


/*Control and Status Register B */
#define UCSRB (*(volatile uint8*)0x2A)

#define RXCIE 7   /* RX Complete Interrupt Enable               */
#define TXCIE 6   /* TX Complete Interrupt Enable               */
#define UDRIE 5   /* USART Data Register Empty Interrupt Enable */
#define RXEN  4   /* Receiver Enable                            */
#define TXEN  3   /* Receiver Enable                            */
#define UCSZ2 2   /* Character Size                             */
#define RXB8  1   /* Receive Data Bit 8                         */
#define TXB8  0   /* Transmit Data Bit 8                        */


/*Control and Status Register C */
#define UCSRC (*(volatile uint8*)0x40)

#define URSEL 7 /* Register Select   */
#define UMSEL 6 /* USART Mode Select */
#define UCPOL 0	/* Clock Polarity */

/* USART Baud Rate Registers – UBRRL and UBRRH */
#define UBRRL (*(volatile uint8*)0x29)
#define UBRRH (*(volatile uint8*)0x40)


#endif /* MCAL_UART_UART_REG_H_ */
