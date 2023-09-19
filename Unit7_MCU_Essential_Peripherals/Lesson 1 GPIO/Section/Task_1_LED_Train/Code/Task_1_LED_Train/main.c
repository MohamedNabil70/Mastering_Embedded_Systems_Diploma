/*
 * Task_1_LED_Train.c
 *
 * Created: 9/19/2023 2:03:39 PM
 * Author : Mohamed Nabil Mohamed
 */ 

//Defines
#define F_CPU 8000000UL
//Includes
#include <util/delay.h>
#include "STD_TYPES.h"
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"



//Function Prototypes
void DIO_init(void);


//main
int main(void)
{
    s8 i;
	
	DIO_init();
	
	//PROGRAM INFINITE LOOP
    while(1) 
    {
		
		//Turn ON all LEDS sequentially
		for(i=0;i<8;i++){
		SET_BIT(PORTB,i);
		_delay_ms(200);
		}
			
		//Turn OFF all LEDS sequentially	
		for(i=7;i>=0;i--){
		CLR_BIT(PORTB,i);
		_delay_ms(200);
		}	
			
			_delay_ms(500);
    }
	
	return 0;
}

void DIO_init(void){
	
	//Port B select all pins mode (OUTPUT)
	DDRB = 0xFF;
}