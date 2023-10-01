/*
 * DCM driver.c
 *
 * Created: 9/27/2022 10:51:30 AM
 * Author : Mohamed Nabil
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
/* UTILS */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"
#include "TMR_interface.h"
#include "TMR_config.h"

/* HAL */
#include "DCM_interface.h"
#include "DCM_config.h"
#include "SWITCH_interface.h"

SWITCH_t b0 = AMIT_BUTTON0;
SWITCH_t b1 = AMIT_BUTTON1;
SWITCH_t b2 = AMIT_BUTTON2;

int main(void)
{
DCM_init();



u8 b0_state,b1_state,b2_state; 

    while (1) 
    {
SWITCH_getState(&b0,&b0_state);
SWITCH_getState(&b1,&b1_state);
SWITCH_getState(&b2,&b2_state);


		if (b0_state == SWITCH_PRESSED)
		{
DCM_on(DCM_MOTOR_A,DCM_CW);
		} 
		else if (b0_state == SWITCH_NOT_PRESSED)
		{
		
		}
		
		if (b1_state == SWITCH_PRESSED)
		{
DCM_off(DCM_MOTOR_A);
		}
		else if (b1_state==SWITCH_NOT_PRESSED)
		{
			
		}
		if (b2_state == SWITCH_PRESSED)
		{
DCM_on(DCM_MOTOR_A,DCM_CCW);
		}
		else if (b2_state==SWITCH_NOT_PRESSED)
		{
			
		}				
		
		
    }
}

