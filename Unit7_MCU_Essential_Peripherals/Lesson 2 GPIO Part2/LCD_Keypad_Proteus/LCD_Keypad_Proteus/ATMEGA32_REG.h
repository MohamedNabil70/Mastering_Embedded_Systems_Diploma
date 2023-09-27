/*
 * ATMEGA32_REG.h
 *
 * Created: 9/6/2022 11:37:21 AM
 *  Author: Mohamed Nabil
 */ 


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

						/*  DIO_REGISTERS  */

//PORT_A_REGISTERS
#define PORTA (*(volatile u8*)0x3B) //output reg
#define DDRA  (*(volatile u8*)0x3A) //direction reg
#define PINA  (*(volatile u8*)0x39) //input reg
//PORT_B_REGISTERS
#define PORTB (*(volatile u8*)0x38)
#define DDRB  (*(volatile u8*)0x37)
#define PINB  (*(volatile u8*)0x36)
//PORT_C_REGISTERS
#define PORTC (*(volatile u8*)0x35)
#define DDRC  (*(volatile u8*)0x34)
#define PINC  (*(volatile u8*)0x33)
//PORT_D_REGISTERS
#define PORTD (*(volatile u8*)0x32)
#define DDRD  (*(volatile u8*)0x31)
#define PIND  (*(volatile u8*)0x30)

/******************************************************************************************/




#endif /* ATMEGA32_REG_H_ */