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
		#include "LCD_interface.h"
		#include "LCD_config.h"

LED_t led0 = AMIT_LED0;
LED_t led1 = AMIT_LED1;
LED_t led2 = AMIT_LED2;
BUZZER_t buzz = AMIT_BUZZER;

int main(void)
{
	
DIO_setPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);  //RXD
DIO_setPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT); //TXD

DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT); //BUZZER

LCD_setPinDirections();
LCD_init();
UART_init();


u8 Rx_data , line1=0,line2=0;

    while (1) 
    {	
	
if (line1<16)
{
UART_RxChar(&Rx_data);
LCD_sendChar(Rx_data);
line1++;
} 
else if (line2<16)
{
	if (line2 == 0)
	{
		LCD_goToSpecificPosition(LCD_LINE_TWO,0);
	}
UART_RxChar(&Rx_data);
LCD_sendChar(Rx_data);
line2++;	
}else{
LCD_clear();
line1 = 0;
line2 = 0;	
}
		
	
	
    }
}

