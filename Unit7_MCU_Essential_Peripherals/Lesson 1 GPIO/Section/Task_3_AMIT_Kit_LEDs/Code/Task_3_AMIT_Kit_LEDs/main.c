/*
 * Task_3_AMIT_Kit_LEDs.c
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
    u8 state = 7;
	
	DIO_init();
	
	//PROGRAM INFINITE LOOP
	 while(1)
	 {
	
		if ( GET_BIT(PIND,0) == 1)
		{
		
		
		if (state > 3)
		{

			SET_BIT(PORTD,state);
			
			if(state == 4)
			{
				_delay_ms(350);
				CLR_BIT(PORTD,state);
			}
			
			//Update state
			state--;
		} 
		else
		{
			//Reset all LEDS and Buzzer
			PORTD = 0;
			//Reset state
			state = 7;
		}
		
		//Trap processor until button is unpressed
		while( GET_BIT(PIND,0) == 1 );
			
		} 

_delay_ms(100);

	}
	
	return 0;
}

void DIO_init(void){
	
	//Port C select all pins mode (OUTPUT)
	DDRC = 0XFF;	
	//Port D select all pins mode 
	DDRD = 0b11111000;

}