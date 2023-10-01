/*
 * STEPM_program.c
 *
 * Created: 9/28/2022 10:04:08 PM
 *  Author: Mohamed Nabil
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
	#include "STEPM_config.h"
	#include "STEPM_interface.h"
	
	
	void STEPM_init(void)
	{
	DIO_setPinDirection(STEPM_PORT,STEPM_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(STEPM_PORT,STEPM_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(STEPM_PORT,STEPM_PIN3,DIO_PIN_OUTPUT);
	DIO_setPinDirection(STEPM_PORT,STEPM_PIN4,DIO_PIN_OUTPUT);
	}
	
	void STEPM_rotateAngle(u32 angleByDegree)
	{
u16 pattern;
u32 iterations;	

iterations=((angleByDegree*512)/360);
for(pattern=0;pattern<iterations;pattern++)
{
	//step 1
	DIO_setPinValue(STEPM_PORT,STEPM_PIN1,DIO_PIN_LOW);
	DIO_setPinValue(STEPM_PORT,STEPM_PIN2,DIO_PIN_HIGH);
	DIO_setPinValue(STEPM_PORT,STEPM_PIN3,DIO_PIN_HIGH);
	DIO_setPinValue(STEPM_PORT,STEPM_PIN4,DIO_PIN_HIGH);
	_delay_ms(10);
	
	//step 2
	DIO_setPinValue(STEPM_PORT,STEPM_PIN1,DIO_PIN_HIGH);
	DIO_setPinValue(STEPM_PORT,STEPM_PIN2,DIO_PIN_LOW);
	DIO_setPinValue(STEPM_PORT,STEPM_PIN3,DIO_PIN_HIGH);
	DIO_setPinValue(STEPM_PORT,STEPM_PIN4,DIO_PIN_HIGH);
	_delay_ms(10);
	
	//step 3
	DIO_setPinValue(STEPM_PORT,STEPM_PIN1,DIO_PIN_HIGH);
	DIO_setPinValue(STEPM_PORT,STEPM_PIN2,DIO_PIN_HIGH);
	DIO_setPinValue(STEPM_PORT,STEPM_PIN3,DIO_PIN_LOW);
	DIO_setPinValue(STEPM_PORT,STEPM_PIN4,DIO_PIN_HIGH);
	_delay_ms(10);
	
	//step 4
	DIO_setPinValue(STEPM_PORT,STEPM_PIN1,DIO_PIN_HIGH);
	DIO_setPinValue(STEPM_PORT,STEPM_PIN2,DIO_PIN_HIGH);
	DIO_setPinValue(STEPM_PORT,STEPM_PIN3,DIO_PIN_HIGH);
	DIO_setPinValue(STEPM_PORT,STEPM_PIN4,DIO_PIN_LOW);
	_delay_ms(10);	
}
		
	}