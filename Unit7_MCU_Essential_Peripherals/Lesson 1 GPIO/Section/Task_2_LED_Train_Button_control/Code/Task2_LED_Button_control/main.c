/*
 * Task2_LED_Button_control.c
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
    u8 state = 0;
	
	DIO_init();
	
	//PROGRAM INFINITE LOOP
	 while(1)
	 {
	
		if ( GET_BIT(PINC,0) == 1)
		{
		
		
		if (state <= 7)
		{
			SET_BIT(PORTB,state);
			state++;
		} 
		else
		{
			//Reset all LEDS
			PORTB = 0;
			//Reset state
			state = 0;
		}
		
		//Trap processor until button is unpressed
		while( GET_BIT(PINC,0) == 1 );
			
		} 


_delay_ms(100);

	}
	
	return 0;
}

void DIO_init(void){
	
	//Port B select all pins mode (OUTPUT)
	DDRB = 0xFF;
	
	//Port C Pin0 select (Input Floating)
	CLR_BIT(DDRC,0);
}