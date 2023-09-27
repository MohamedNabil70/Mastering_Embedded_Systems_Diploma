/*
 * KPD_program.c
 *
 * Created: 9/13/2022 10:06:03 AM
 *  Author: Mohamed Nabil
 */ 

	/*UTILES LIB*/
	#include "STD_TYPES.h"
	#include "BIT_MATH.h"
	#include "ATMEGA32_REG.h"

	/* MCAL */
	#include "DIO_interface.h"
	
	/* HAL */
	#include "KPD_config.h"
	#include "KPD_interface.h"
	

void KPD_getValue(u8* returnedValue)
{
*returnedValue = KPD_NOT_PRESSED;  //if returnedValue remains KPD_NOT_PRESSED then no change is done

u8 KPD_Chars[KPD_ROWS_NUM][KPD_COLS_NUM] = KPD_KEYS;
u8 colPins[KPD_COLS_NUM] = {KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN};
u8 rowPins[KPD_ROWS_NUM] = {KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

if (returnedValue!=NULL)
{			   
u8 row,column,i;
u8 pinValue;	
u8 pinFlag=0;
					   									   
for (column=0;column<KPD_COLS_NUM;column++)
{

for(i=0;i<KPD_COLS_NUM;i++){
	//Deactivate all columns
	DIO_setPinValue(KPD_COLS_PORT,colPins[i],DIO_PIN_HIGH);
}

	//Activate current column
DIO_setPinValue(KPD_COLS_PORT,colPins[column],DIO_PIN_LOW);	
	for (row=0;row<KPD_ROWS_NUM;row++)
	{
//Read current row
DIO_getPinValue(KPD_ROWS_PORT,rowPins[row],&pinValue);
	if (pinValue == 0)
	{
//Read current row and column ascii if pressed
		*returnedValue=KPD_Chars[row][column];
	    //as long as you hold the key the *while* will stop the algorithm from repeating
		while (pinValue == 0)
		{
		DIO_getPinValue(KPD_ROWS_PORT,rowPins[row],&pinValue);	
		}
		pinFlag=1;
		break;
	}
	}
//Deactivate current column
DIO_setPinValue(KPD_COLS_PORT,colPins[column],DIO_PIN_HIGH);

			if (pinFlag == 1)
			{
				break;
			}
}	
}

}
	