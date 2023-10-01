/*
 * SSD_program.c
 *
 * Created: 9/18/2022 12:42:18 PM
 *  Author: Mohamed Nabil
 */ 

#define  F_CPU 16000000
#include <util/delay.h>
	/*UTILES LIB*/
	#include "STD_TYPES.h"
	#include "BIT_MATH.h"
	#include "ATMEGA32_REG.h"

	/* MCAL */
	#include "DIO_interface.h"
	
	/* HAL */
		#include "SSD_interface.h"


	/* Main Functions*/

void SSD_on(void)
{
DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
}

void SSD_off(void)
{
DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
DIO_setPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);	
}

void SSD_displayDigit(u8 digit)
{
writeHalfPort(digit);	
}

static void writeHalfPort(u8 value)
{
	if(1 == GET_BIT(value,0))
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
		}else{
		DIO_setPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
	}
	if(1 == GET_BIT(value,1))
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
		}else{
		DIO_setPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
	}
	if(1 == GET_BIT(value,2))
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
		}else{
		DIO_setPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
	}
	if(1 == GET_BIT(value,3))
	{
		DIO_setPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
		}else{
		DIO_setPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
	}
	
}

	/* Additional Functions*/


//Display 2 Digit Number Functions

void SSD_displayNumber(u8 number)
{

		SSD_displayDigit(number/10);
		SSD_on_left();
		_delay_ms(5);
		SSD_off_left();
		
		SSD_displayDigit(number%10);
		SSD_on_right();
		_delay_ms(5);
		SSD_off_right();

}


void SSD_displayNumberFor1Second(u8 number)
{
	if (number < 100)
	{
		u8 delay=0;
		while(delay < 100)
		{
			SSD_displayDigit(number/10);
			SSD_on_left();
			_delay_ms(5);
			SSD_off_left();
			
			SSD_displayDigit(number%10);
			SSD_on_right();
			_delay_ms(5);
			SSD_off_right();
			delay++;
		}
	}
}



void SSD_displayNumber_forSpicificTime(u8 number,u8 seconds)
{
	if (number < 100)
	{
		u8 delay=0;
		while(delay<100*seconds)
		{
			SSD_displayDigit(number/10);
			SSD_on_left();
			_delay_ms(5);
			SSD_off_left();
			
			SSD_displayDigit(number%10);
			SSD_on_right();
			_delay_ms(5);
			SSD_off_right();
			delay++;
		}
	}
}

//Counter Functions (not generic)

void SSD_countUp(u8 seconds)
{
SSD_off();
s8 count;
for(count=0;count<seconds;count++)
{
	DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(25);
	DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
	SSD_displayNumberFor1Second(count);

}	
}

void SSD_countDown(u8 seconds)
{
SSD_off();
s8 count;
for(count=seconds;count>=0;count--)
{
	DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(25);
	DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
	SSD_displayNumberFor1Second(count);

}	
}

//Digit [on/off] Functions

void SSD_on_right(void)
{
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
}

void SSD_on_left(void)
{
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
}

void SSD_off_right(void)
{
	DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);

}

void SSD_off_left(void)
{
	DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
}

