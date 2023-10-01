/*****************************************************************************************
******************************************************************************************
**********************		 	Date:11/9/2022                      **********************
**********************			Name: Mohamed Nabil                 **********************
**********************		  	Version: 1.0                        **********************
**********************		 	SWC: LED INTERFACE                  **********************
******************************************************************************************
******************************************************************************************
*/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


/*************************************************/

//Macros for AMIT KIT LEDS
#define AMIT_LED0 {DIO_PORTC,DIO_PIN2,LED_FORWARD}
#define AMIT_LED1 {DIO_PORTC,DIO_PIN7,LED_FORWARD}
#define AMIT_LED2 {DIO_PORTD,DIO_PIN3,LED_FORWARD}

/*************************************************/
//MACROS FOR CONNECTION_TYPE
#define LED_FORWARD		0
#define LED_REVERSE		1

typedef struct 
{
	u8 PortId;
	u8 PinId;
	u8 ConnectionType;
	}LED_t;
	
//FUNCTIONS
void LED_on(LED_t* ptr);
void LED_off(LED_t* ptr);
void LED_toggle(LED_t* ptr);


#endif
