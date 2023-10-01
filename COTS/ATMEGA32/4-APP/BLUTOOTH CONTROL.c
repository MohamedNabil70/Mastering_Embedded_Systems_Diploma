/*
 * UART TEST.c
 *
 * Created: 10/4/2022 9:33:15 AM
 * Author : Mohamed Nabil
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>		
		
		/* UTILS */
		#include "STD_TYPES.h"
		#include "BIT_MATH.h"
		#include "ATMEGA32_REG.h"

		/* MCAL */
		#include "UART_interface.h"
		#include "DIO_interface.h"
		#include "LED_interface.h"
		#include "BUZZER_interface.h"

LED_t led0 = AMIT_LED0;
LED_t led1 = AMIT_LED1;
LED_t led2 = AMIT_LED2;
BUZZER_t buzz = AMIT_BUZZER;

int main(void)
{
	
DIO_setPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);  //RXD
DIO_setPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT); //TXD

DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT); //BUZZER

	/*LCD CONTROL Pins Direction */
	DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);

	/*LCD Data Pins Direction */
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);

UART_init();


u8 Rx_data;

    while (1) 
    {
	UART_RxChar(&Rx_data);		
	
	switch(Rx_data)
	{
	case 'A':
BUZZER_tick(&buzz);
LED_on(&led1);
_delay_ms(200);
LED_off(&led1);
	break;

	case 'B':
BUZZER_tick(&buzz);
LED_on(&led0);
_delay_ms(200);
LED_off(&led0);	
	break;

	case 'C':
BUZZER_tick(&buzz);
LED_on(&led2);
_delay_ms(200);
LED_off(&led2);	
	break;

	case 'D':
BUZZER_tick(&buzz);
LED_on(&led0);
LED_on(&led1);
LED_on(&led2);
_delay_ms(100);
LED_off(&led0);
LED_off(&led1);
LED_off(&led2);
	break;
	
	case 'X':
BUZZER_tick(&buzz);
	break;

		
	}
	
    }
}

