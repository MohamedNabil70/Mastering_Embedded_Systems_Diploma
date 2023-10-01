/*
 * Servo_Test.c
 *
 * Created: 9/30/2022 10:38:38 PM
 * Author : NoUr MD
 */ 

#define F_CPU 16000000UL
#include <util\delay.h>

//UTILES
#include "TYPE_DEF.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "DIO_Interface.h"
#include "TMR_Interface.h"
#include "TMR_Config.h"

//HAL
#include "Servo_Interface.h"
#include "LCD_Interface.h"

int main(void)
{
	LCD_Start_AMIT();
	LCD_Init();
	s8 i;

    while (1) 
    {
		
		for(i=-30;i<=30;i++){
			Servo_RotateDegree(i);
			LCD_writeNumber(i+90);
			_delay_ms(10);
			LCD_clear();
		}
		for(i=30;i>=-30;i--){
			Servo_RotateDegree(i);
			LCD_writeNumber(i+90);
			_delay_ms(10);
			LCD_clear();
		}

	}
}

