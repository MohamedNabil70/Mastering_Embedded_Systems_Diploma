/*
 * ADC Driver.c
 *
 * Created: 9/20/2022 11:51:34 AM
 * Author : Mohamed Nabil
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>	
	/*UTILES LIB*/
	#include "STD_TYPES.h"
	#include "BIT_MATH.h"
	#include "ATMEGA32_REG.h"

	/* MCAL */
	#include "ADC_interface.h"
	#include "DIO_interface.h"

	#include "LCD_interface.h"
	#include "LCD_config.h"


int main(void)
{
  /*LCD DATA Pins Direction */
 DIO_setPinDirection(LCD_D4_PORT,DIO_PIN4,DIO_PIN_OUTPUT);
 DIO_setPinDirection(LCD_D5_PORT,DIO_PIN5,DIO_PIN_OUTPUT);
 DIO_setPinDirection(LCD_D6_PORT,DIO_PIN6,DIO_PIN_OUTPUT);
 DIO_setPinDirection(LCD_D7_PORT,DIO_PIN7,DIO_PIN_OUTPUT);
 /* Control Pins Direction */
 DIO_setPinDirection(LCD_E_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
 DIO_setPinDirection(LCD_E_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
 DIO_setPinDirection(LCD_E_PORT,LCD_E_PIN,DIO_PIN_OUTPUT);

/* POT Direction */
 DIO_setPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_INPUT); 

/* Buzzer Direction */

DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);

	ADC_init();
	LCD_init();

	
	u16 test=0,AnalogVal;
	while (1) 
    {
	ADC_getAnalogValue(ADC_CHANNEL_1,&AnalogVal);

	_delay_ms(35);
	if(test!=AnalogVal)
	{
			LCD_clear();
			LCD_goToSpecificPosition(LCD_LINE_ONE,6);
			LCD_writeNumber(AnalogVal);
		DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
		_delay_ms(30);
		DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
		test=AnalogVal;	
	}else{
		
	}
continue;
	}
	

}

