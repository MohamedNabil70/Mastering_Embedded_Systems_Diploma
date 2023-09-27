/*
 * KPD_test.c
 *
 * Created: 9/27/2023 3:28:06 PM
 * Author : Moahmed Nabil
 */ 


#define F_CPU 8000000UL
#include <util/delay.h>
/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "KPD_interface.h"
#include "KPD_config.h"
#include "LCD_interface.h"
#include "LCD_config.h"

int main(void)
{
  LCD_setPinDirections();
  LCD_init();
  
	DIO_setPinDirection(KPD_COLS_PORT,KPD_COL0_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COLS_PORT,KPD_COL1_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COLS_PORT,KPD_COL2_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COLS_PORT,KPD_COL3_PIN,DIO_PIN_OUTPUT);
	
	DIO_setPinDirection(KPD_ROWS_PORT,KPD_ROW0_PIN,DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROWS_PORT,KPD_ROW1_PIN,DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROWS_PORT,KPD_ROW2_PIN,DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROWS_PORT,KPD_ROW3_PIN,DIO_PIN_INPUT);
	
	DIO_setInputPinResistence(KPD_ROWS_PORT,KPD_ROW0_PIN);
	DIO_setInputPinResistence(KPD_ROWS_PORT,KPD_ROW1_PIN);
	DIO_setInputPinResistence(KPD_ROWS_PORT,KPD_ROW2_PIN);
	DIO_setInputPinResistence(KPD_ROWS_PORT,KPD_ROW3_PIN);
	

	u8 kpdkey,line_guard=0;
    while (1) 
    {
		
		
		KPD_getValue(&kpdkey);
		
		if(KPD_NOT_PRESSED != kpdkey)
		{
			
				if (line_guard==16)
				{
					LCD_goToSpecificPosition(LCD_LINE_TWO,0);
				} 
				else if(line_guard>32)
				{
					line_guard=0;
					LCD_clear();
				}



			if (kpdkey=='!')
			{
				LCD_clear();
				}else				
			LCD_sendChar(kpdkey);
			
			line_guard++;

		
		}
					
	}
			
			
   
}