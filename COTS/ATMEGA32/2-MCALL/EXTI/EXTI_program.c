/*
 * EXTI_program.c
 *
 * Created: 9/15/2022 12:06:09 PM
 *  Author: Mohamed Nabil
 */ 

	/*UTILES LIB*/
	#include "STD_TYPES.h"
	#include "BIT_MATH.h"
	#include "ATMEGA32_REG.h"

	/* MCAL */
	#include "EXTI_interface.h"
	
static void(*INT0_pCallBack)(void) = NULL;	
static void(*INT1_pCallBack)(void) = NULL;
static void(*INT2_pCallBack)(void) = NULL;
						
							/* APIS PROTOTYPES */

void EXTI_enable(EXTI_source interruptSource,EXTI_trigger interruptTrigger)
{

switch(interruptSource)
	{

case EXTI_INT0:
if (interruptTrigger == EXTI_RISING_EDGE)
{
SET_BIT(MCUCR,0);
SET_BIT(MCUCR,1);	
} 
else if (interruptTrigger == EXTI_FALLING_EDGE)
{
CLR_BIT(MCUCR,0);
SET_BIT(MCUCR,1);	
}else if(interruptTrigger == EXTI_LOW_LEVEL)
{
CLR_BIT(MCUCR,0);
CLR_BIT(MCUCR,1);
}else if(interruptTrigger == EXTI_ANY_LOGICAL_CHANGE)
{
SET_BIT(MCUCR,0);
CLR_BIT(MCUCR,1);	
}
SET_BIT(GICR,6);  //enable INT0
break;	

case EXTI_INT1:
if (interruptTrigger == EXTI_RISING_EDGE)
{
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
}
else if (interruptTrigger == EXTI_FALLING_EDGE)
{
	CLR_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
}else if(interruptTrigger == EXTI_LOW_LEVEL)
{
	CLR_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
}else if(interruptTrigger == EXTI_ANY_LOGICAL_CHANGE)
{
	SET_BIT(MCUCR,2);
	CLR_BIT(MCUCR,3);
}
SET_BIT(GICR,7);  //enable INT1
break;

case EXTI_INT2:
if (interruptTrigger == EXTI_RISING_EDGE)
{
	SET_BIT(MCUCSR,6);	
}
else if (interruptTrigger == EXTI_FALLING_EDGE)
{
	CLR_BIT(MCUCSR,6);
}
SET_BIT(GICR,5);  //enable INT2
break;
	
	}
}

void EXTI_disble(EXTI_source interruptSource)
{
	switch(interruptSource)
	{
		case EXTI_INT0:
		CLR_BIT(GICR,6);  //enable INT0
		break;
		
		case EXTI_INT1:
		CLR_BIT(GICR,7);  //enable INT1
		break;
		
		case EXTI_INT2:
		CLR_BIT(GICR,5);  //enable INT2
		break;
	}
}

					/* Set Call Back Functions */

void EXTI_INT0SetCallBack(void(*ptr)(void))
{
	if (ptr!=NULL)
	{
	INT0_pCallBack=ptr;	
	}
	
}

void EXTI_INT1SetCallBack(void(*ptr)(void))
{
	if (ptr!=NULL)
	{
		INT1_pCallBack=ptr;
	}
	
}

void EXTI_INT2SetCallBack(void(*ptr)(void))
{
	if (ptr!=NULL)
	{
		INT2_pCallBack=ptr;
	}
	
}

//ISR Function prototype for EXTI0
void __vector_1(void) __attribute__ ((signal));
void __vector_1(void)
{

	if (INT0_pCallBack!=NULL)
	{
		//call action
		INT0_pCallBack();
	}
}

//ISR Function prototype for EXTI1
void __vector_2(void) __attribute__ ((signal));
void __vector_2(void)
{

	if (INT1_pCallBack!=NULL)
	{
		//call action
		INT1_pCallBack();
	}
}

//ISR Function prototype for EXTI2
void __vector_3(void) __attribute__ ((signal));
void __vector_3(void)
{

	if (INT2_pCallBack!=NULL)
	{
		//call action
		INT2_pCallBack();
	}
}
