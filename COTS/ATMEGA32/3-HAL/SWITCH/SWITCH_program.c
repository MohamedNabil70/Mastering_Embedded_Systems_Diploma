/*****************************************************************************************
******************************************************************************************
**********************		 	Date:11/9/2022                      **********************
**********************			Name: Mohamed Nabil                 **********************
**********************		  	Version: 1.0                        **********************
**********************		 	SWC: SWITCH_PROGRAM.c               **********************
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
#include "SWITCH_interface.h"


void SWITCH_getState(SWITCH_t* switchData,u8* switchState)
{
u8 local_switchState;
if((switchState != NULL) && (switchData!=NULL))
{	
if((switchData->PortId<=3)&&(switchData->PinId<=7)&&((switchData->ConnectionType == SWITCH_FORWARD)||(switchData->ConnectionType == SWITCH_REVERSE)))
{
	
	
if(switchData->ConnectionType == SWITCH_FORWARD)
{
DIO_setPinDirection(switchData->PortId,switchData->PinId,DIO_PIN_INPUT);
DIO_getPinValue(switchData->PortId,switchData->PinId,&local_switchState);

if(local_switchState==DIO_PIN_HIGH)
{
*switchState = SWITCH_PRESSED ;
}else{
*switchState = SWITCH_NOT_PRESSED ;	
}

}else if (switchData->ConnectionType == SWITCH_REVERSE){
DIO_setPinDirection(switchData->PortId,switchData->PinId,DIO_PIN_INPUT);
DIO_setInputPinResistence(switchData->PortId,switchData->PinId);
DIO_getPinValue(switchData->PortId,switchData->PinId,&local_switchState);

if(local_switchState==DIO_PIN_LOW)
{
*switchState = SWITCH_PRESSED ;
}else{
*switchState = SWITCH_NOT_PRESSED ;	
}

}

}	

}
}
