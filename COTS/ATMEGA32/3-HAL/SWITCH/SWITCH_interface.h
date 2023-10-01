/*****************************************************************************************
******************************************************************************************
**********************		 	Date:11/9/2022                      **********************
**********************			Name: Mohamed Nabil                 **********************
**********************		  	Version: 1.0                        **********************
**********************		 	SWC: SWITCH_INTERFACE.h             **********************
******************************************************************************************
******************************************************************************************
*/


#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

//AMIT KIT Buttons MACROS
#define AMIT_BUTTON0     {DIO_PORTB,DIO_PIN0,SWITCH_FORWARD}
#define AMIT_BUTTON1     {DIO_PORTD,DIO_PIN6,SWITCH_FORWARD}
#define AMIT_BUTTON2     {DIO_PORTD,DIO_PIN2,SWITCH_FORWARD}
		
//MACROS FOR CONNECTION_TYPE
#define SWITCH_FORWARD		1
#define SWITCH_REVERSE		0

#define SWITCH_PRESSED			0
#define SWITCH_NOT_PRESSED		1

typedef struct 
{
u8 PortId;
u8 PinId;
u8 ConnectionType;
}SWITCH_t;


void SWITCH_getState(SWITCH_t* switchData,u8* switchState);



#endif