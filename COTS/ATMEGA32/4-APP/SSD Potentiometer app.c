/*
 * SSD driver.c
 *
 * Created: 9/18/2022 12:41:43 PM
 * Author : Mohamed Nabil
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
	/*UTILES LIB*/
	#include "STD_TYPES.h"
	#include "BIT_MATH.h"
	#include "ATMEGA32_REG.h"

	/* MCAL */
	#include "DIO_interface.h"
	
	/* HAL */
	#include "SSD_interface.h"

int main(void)
{
	DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);

	/* Data Pins Direction */
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);

	DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);



SSD_countUp(20);
SSD_countDown(20);

DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);

SSD_displayNumber_forSpicificTime(0,2);

DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);

DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);

    while (1) 
    {
		
    }
}
 



