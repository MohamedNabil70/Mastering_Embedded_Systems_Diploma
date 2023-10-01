/*
 * RELAY_program.h
 *
 * Created: 9/27/2022 10:52:08 AM
 *  Author: Mohamed Nabil
 */ 
 
 
 /* UTILS */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "RELAY_interface.h"


void RELAY_on(RELAY_t* relayData)
{
if(relayData!=NULL)
{
DIO_setPinDirection(relayData->PortId,relayData->PinId,DIO_PIN_OUTPUT);
DIO_setPinValue(relayData->PortId,relayData->PinId,DIO_PIN_HIGH);
	
}
}

void RELAY_off(RELAY_t* relayData)
{
if(relayData!=NULL)
{
DIO_setPinDirection(relayData->PortId,relayData->PinId,DIO_PIN_OUTPUT);
DIO_setPinValue(relayData->PortId,relayData->PinId,DIO_PIN_LOW);
	
}

}