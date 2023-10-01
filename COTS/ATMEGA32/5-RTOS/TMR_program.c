/*
 * TMR_program.c
 *
 * Created: 9/25/2022 5:55:55 AM
 *  Author: Mohamed Nabil 
 */ 

		/* UTILS */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

		/* MCAL */
#include "TMR_interface.h"
#include "TMR_config.h"




static void(*TMR_timer0_CTC_pCallBack)(void) = NULL;



/***************************************************************************************************************/
/*                                                                                                             */
/***************************************************************************************************************/


					/*TIMER 0*/



void TMR_timer0init(void)
{ 

//Select Mode = CTC Mode
SET_BIT(TCCR0,3);
CLR_BIT(TCCR0,6);

//Enable CTC Interrupt
SET_BIT(TIMSK,1);

}


void TMR_timer0start(void)
{
#if TMR_TMR0_PRESCALER_FACTOR == TMR_TMR0_PRESCALER_1

//Set Prescaller Value = controller input Frequency
SET_BIT(TCCR0,0);
CLR_BIT(TCCR0,1);
CLR_BIT(TCCR0,2);

#elif TMR_TMR0_PRESCALER_FACTOR == TMR_TMR0_PRESCALER_8	 

//Set Prescaller Value = 8
CLR_BIT(TCCR0,0);
SET_BIT(TCCR0,1);
CLR_BIT(TCCR0,2);
								   
#elif TMR_TMR0_PRESCALER_FACTOR == TMR_TMR0_PRESCALER_64	  

//Set Prescaller Value = 64
SET_BIT(TCCR0,0);
SET_BIT(TCCR0,1);
CLR_BIT(TCCR0,2);
								   
#elif TMR_TMR0_PRESCALER_FACTOR == TMR_TMR0_PRESCALER_256	 

//Set Prescaller Value = 256
CLR_BIT(TCCR0,0);
CLR_BIT(TCCR0,1);
SET_BIT(TCCR0,2);
								   
#elif TMR_TMR0_PRESCALER_FACTOR == TMR_TMR0_PRESCALER_1024	 

//Set Prescaller Value = 1024
SET_BIT(TCCR0,0);
CLR_BIT(TCCR0,1);
SET_BIT(TCCR0,2);
								   
#elif TMR_TMR0_PRESCALER_FACTOR == TMR_TMR0_PRESCALER_EXT_FE 

//Set Prescaller to External clock source on T0 pin. Clock on falling edge.
CLR_BIT(TCCR0,0);
SET_BIT(TCCR0,1);
SET_BIT(TCCR0,2);
								   
#elif TMR_TMR0_PRESCALER_FACTOR == TMR_TMR0_PRESCALER_EXT_RE 

//Set Prescaller to External clock source on T0 pin. Clock on rising edge.
SET_BIT(TCCR0,0);
SET_BIT(TCCR0,1);
SET_BIT(TCCR0,2);



#endif
	
}

void TMR_timer0stop(void)
{
//Set Prescaller bits = 000
CLR_BIT(TCCR0,0);
CLR_BIT(TCCR0,1);
CLR_BIT(TCCR0,2);	
}



void TMR_timer0SetCompareMatchValue(u8 OCR0_Value )
{
//	init timer HARDWARE with compare value [Output Compare REG]
OCR0 = OCR0_Value;
}



void TMR_timer0_CTC_setCallBack(void(*ptr)(void))
{
if (ptr!=NULL)
{
	TMR_timer0_CTC_pCallBack=ptr;
}	

}

				/* ISR Functions */

// ISR Function Prototype for Timer0 CTC
void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{

if (TMR_timer0_CTC_pCallBack!=NULL)
{			   
	TMR_timer0_CTC_pCallBack();
}
}


/***************************************************************************************************************/
/*                                                                                                             */
/***************************************************************************************************************/							


						
			
		
