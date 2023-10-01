/*
 * SERVO_project.c
 *
 * Created: 9/30/2022 10:11:00 PM
 *  Author: Mohamed Nabil
 */ 

#define  F_CPU 16000000UL
#include <util/delay.h>
	/*UTILES LIB*/
	#include "STD_TYPES.h"
	#include "BIT_MATH.h"
	#include "ATMEGA32_REG.h"

	/* MCAL */
	#include "SERVO_interface.h"
	#include "TMR_interface.h"
	#include "TMR_config.h"	
	#include "DIO_interface.h"
	
	
	void SERVO_on(u8 drivingTimer,s8 DesiredAngle)
	{
	if (((drivingTimer == SERVO_DRIVING_TIMER_1) || (drivingTimer == SERVO_DRIVING_TIMER_2)) && (DesiredAngle >= -90) && (DesiredAngle <= 90) )
	{
	switch(drivingTimer)
	{
	case SERVO_DRIVING_TIMER_1 :
	/*
	* timer 1 mode must be set from config file to TMR_TMR0_FAST_PWM_MODE
	& TMR_TMR1_OVF_VALUE = 4999			  (20ms ovf time)
	
	* Select PWM MODE = Non Inverting 
	
	* prescaler Value = 64  
	*/
DIO_setPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
		
		TMR_timer1init();
	TMR_timer1SetCompareMatchAValue(249+((25*(90+DesiredAngle))/18));
  
  	TMR_timer1start();
	
	break;
	
	case SERVO_DRIVING_TIMER_2 :
	
		
	break;	
	}
	
	}
	
	}
