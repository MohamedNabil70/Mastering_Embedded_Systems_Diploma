/*
 * EXTI_interface.h
 *
 * Created: 9/15/2022 12:06:47 PM
 *  Author: Mohamed Nabil
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
//Enum for interrupt Source
typedef enum 
{
EXTI_INT0,  //PORTD_PIN2
EXTI_INT1,	//PORTD_PIN3
EXTI_INT2	//PORTB_PIN2
}EXTI_source;

/* Enum for interrupt Source */
typedef enum
{
	EXTI_RISING_EDGE,
	EXTI_FALLING_EDGE,
	EXTI_LOW_LEVEL,
	EXTI_ANY_LOGICAL_CHANGE
}EXTI_trigger;

 
						/* APIS PROTOTYPES */
void EXTI_enable(EXTI_source interruptSource,EXTI_trigger interruptTrigger);
void EXTI_disble(EXTI_source interruptSource);

					/* Set Call Back Functions */
// (functions that deliver address of ISR action functions from main)
void EXTI_INT0SetCallBack(void(*ptr)(void));
void EXTI_INT1SetCallBack(void(*ptr)(void));
void EXTI_INT2SetCallBack(void(*ptr)(void));

#endif /* EXTI_INTERFACE_H_ */