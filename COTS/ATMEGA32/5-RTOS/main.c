/*
 * RTOS test.c
 *
 * Created: 10/18/2022 10:01:53 AM
 * Author :  Mohamed Nabil 
 */ 

		/* UTILS */
		#include "STD_TYPES.h"
		#include "BIT_MATH.h"
		#include "ATMEGA32_REG.h"

		/* MCAL */
		#include "DIO_Interface.h"
		
		/* RTOS STACK */
		#include "KERNAL_interface.h"

void led_0(void);
void led_1(void);
void led_2(void);
void buzzer(void);


int main(void)
{
//leds
DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);	
DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);


RTOS_createTask(0,500,&led_0);
RTOS_createTask(1,500,&led_1);
RTOS_createTask(2,500,&led_2);
RTOS_createTask(3,3000,&buzzer);

RTOS_deleteTask(0);
RTOS_createTask(0,3000,&led_0);




RTOS_start(); 

  
    while (1) 
    {

		
    }
}

void led_0(void)
{
DIO_togglePinValue(DIO_PORTC,DIO_PIN2);	
}

void led_1(void)
{
DIO_togglePinValue(DIO_PORTC,DIO_PIN7);		
}
void led_2(void)
{
DIO_togglePinValue(DIO_PORTD,DIO_PIN3);		
}

void buzzer(void)
{
	DIO_togglePinValue(DIO_PORTA,DIO_PIN3);

}