/*
 * RELAY_interface.h
 *
 * Created: 9/27/2022 10:52:08 AM
 *  Author: Mohamed Nabil
 */ 


#ifndef RELAY_INTERFACE_H_
#define RELAY_INTERFACE_H_

//Macros for AMIT KIT RELAY
#define AMIT_RELAY {DIO_PORTA,DIO_PIN2}

typedef struct
{
	u8 PortId;
	u8 PinId;	
}RELAY_t;


//Kit Relay control
void RELAY_on(RELAY_t* relayData); 
void RELAY_off(RELAY_t* relayData);

#endif /* RELAY_INTERFACE_H_ */