/*****************************************************************************************
******************************************************************************************
**********************		 	Date:5/10/2022                      **********************
**********************			Name: Mohamed Nabil                 **********************
**********************		  	Version: 1.0                        **********************
**********************		 	SWC: BUZZER INTERFACE               **********************
******************************************************************************************
******************************************************************************************
*/

#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_


/*************************************************/

//Macros for AMIT KIT BUZZER
#define AMIT_BUZZER {DIO_PORTA,DIO_PIN3}


/*************************************************/

//MACROS FOR CONNECTION_TYPE
#define BUZZER_FORWARD		0
#define BUZZER_REVERSE		1

typedef struct 
{
	u8 PortId;
	u8 PinId;
	u8 ConnectionType;
	}BUZZER_t;
	
	/* Main Functions */
void BUZZER_on(BUZZER_t* ptr);
void BUZZER_off(BUZZER_t* ptr);
void BUZZER_toggle(BUZZER_t* ptr);

	/* Other Functions */
	
void BUZZER_tick(BUZZER_t* ptr);

#endif
