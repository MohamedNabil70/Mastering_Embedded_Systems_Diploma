/*****************************************************************************************
******************************************************************************************
**********************		 	Date:11/9/2022                      **********************
**********************			Name: Mohamed Nabil                 **********************
**********************		  	Version: 1.0                        **********************
**********************		 	SWC: LED PROGRAM                    **********************
******************************************************************************************
******************************************************************************************
*/

	/*UTILES LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"  

	/* MCAL */
#include "DIO_interface.h"

	/* HAL */
#include "LED_interface.h"

void LED_on(LED_t* ptr)
{
if((ptr!=NULL) && (ptr-> PortId<=3) && (ptr-> PinId<=7) && ((ptr-> ConnectionType == LED_FORWARD) || (ptr-> ConnectionType == LED_REVERSE)))
{
if(ptr-> ConnectionType == LED_FORWARD)
{
DIO_setPinDirection(ptr-> PortId,ptr-> PinId,DIO_PIN_OUTPUT);
DIO_setPinValue(ptr-> PortId,ptr-> PinId,DIO_PIN_HIGH);	
}else{
DIO_setPinDirection(ptr-> PortId,ptr-> PinId,DIO_PIN_OUTPUT);
DIO_setPinValue(ptr-> PortId,ptr-> PinId,DIO_PIN_LOW);
}	
	}	
}

void LED_off(LED_t* ptr)
{
if((ptr!=NULL) && (ptr->PortId<=3)&&(ptr->PinId<=7)&&((ptr->ConnectionType == LED_FORWARD)||(ptr->ConnectionType == LED_REVERSE)))
	{
		if(ptr->ConnectionType == LED_FORWARD)
		{
			DIO_setPinDirection(ptr->PortId,ptr->PinId,DIO_PIN_OUTPUT);
			DIO_setPinValue(ptr->PortId,ptr->PinId,DIO_PIN_LOW);
			}else{
			DIO_setPinDirection(ptr->PortId,ptr->PinId,DIO_PIN_OUTPUT);
			DIO_setPinValue(ptr->PortId,ptr->PinId,DIO_PIN_HIGH);
		}
	}	
}
void LED_toggle(LED_t* ptr)
{
if((ptr!=NULL) && (ptr->PortId<=3)&&(ptr->PinId<=7))
{
		DIO_setPinDirection(ptr->PortId,ptr->PinId,DIO_PIN_OUTPUT);
		DIO_togglePinValue(ptr->PortId,ptr->PinId);
}	
	
}

