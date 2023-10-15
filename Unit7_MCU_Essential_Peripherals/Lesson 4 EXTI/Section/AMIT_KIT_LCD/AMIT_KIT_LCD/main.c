/*
 * LCD_KPD_test
 *
 * Created: 9/27/2023 3:28:06 PM
 * Author : Moahmed Nabil
 */ 


#define F_CPU 16000000UL
#include <util/delay.h>
/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */

#include "LCD_interface.h"
#include "LCD_config.h"

int main(void)
{
  LCD_setPinDirections();
  LCD_init();
  LCD_clear();	


LCD_typeString("Learn In Depth");
LCD_goToSpecificPosition(LCD_LINE_TWO,0);
LCD_typeString("~Mohamed Nabil");

    while (1) 
    {
		
 //nothing
					
	}
			
			
   
}