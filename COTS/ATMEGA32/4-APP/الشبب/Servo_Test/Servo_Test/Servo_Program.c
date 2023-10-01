/*
 * Servo_Program.c
 *
 * Created: 9/30/2022 10:40:22 PM
 *  Author: NoUr MD
 */ 


//UTILES
#include "TYPE_DEF.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "DIO_Interface.h"
#include "TMR_Interface.h"
#include "TMR_Config.h"


void Servo_OFF (void){
	TMR_timer2stop();
}

void Servo_RotateDegree(s8 Angle){
	
			DIO_SetPinDirection(DIO_PORTD,DIO_PIN7,DIO_PIN_OUTPUT);
			TMR_timer2init();
			TMR_timer2SetCompareMatchValue(2*Angle+190);//-90 = 100
			TMR_timer2start();
}