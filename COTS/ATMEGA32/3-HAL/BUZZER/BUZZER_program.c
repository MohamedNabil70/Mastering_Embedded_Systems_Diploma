/*****************************************************************************************
******************************************************************************************
**********************		 	Date:5/10/2022                      **********************
**********************			Name: Mohamed Nabil                 **********************
**********************		  	Version: 1.0                        **********************
**********************		 	SWC: BUZZER INTERFACE               **********************
******************************************************************************************
******************************************************************************************
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
	#include "BUZZER_interface.h"
	
	/* Main Functions */
void BUZZER_on(BUZZER_t* ptr)
{
if((ptr!=NULL) && (ptr-> PortId<=3) && (ptr-> PinId<=7) && ((ptr-> ConnectionType == BUZZER_FORWARD) || (ptr-> ConnectionType == BUZZER_REVERSE)))
{
DIO_setPinDirection(ptr-> PortId,ptr-> PinId,DIO_PIN_OUTPUT);	
if(ptr-> ConnectionType == BUZZER_FORWARD)
{
DIO_setPinValue(ptr-> PortId,ptr-> PinId,DIO_PIN_HIGH);	
}else{
DIO_setPinValue(ptr-> PortId,ptr-> PinId,DIO_PIN_LOW);
}	
	}		
}

void BUZZER_off(BUZZER_t* ptr)
{
if((ptr!=NULL) && (ptr-> PortId<=3) && (ptr-> PinId<=7) && ((ptr-> ConnectionType == BUZZER_FORWARD) || (ptr-> ConnectionType == BUZZER_REVERSE)))
{
	DIO_setPinDirection(ptr-> PortId,ptr-> PinId,DIO_PIN_OUTPUT);
	if(ptr-> ConnectionType == BUZZER_FORWARD)
	{
		DIO_setPinValue(ptr-> PortId,ptr-> PinId,DIO_PIN_LOW);
		}else{
		DIO_setPinValue(ptr-> PortId,ptr-> PinId,DIO_PIN_HIGH);
	}
}	
}

void BUZZER_toggle(BUZZER_t* ptr)
{
	DIO_setPinDirection(ptr-> PortId,ptr-> PinId,DIO_PIN_OUTPUT);
	DIO_togglePinValue(ptr-> PortId,ptr-> PinId);
}


	/* Other Functions */


void BUZZER_tick(BUZZER_t* ptr)
{
	if (ptr != NULL)
	{
		BUZZER_on(ptr);
		_delay_ms(30);
		BUZZER_off(ptr);
	}	
}
