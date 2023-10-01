/*
 * UART_program.c
 *
 * Created: 10/4/2022 9:34:53 AM
 *  Author: Mohamed Nabil
 */ 


		/* UTILS */
		#include "STD_TYPES.h"
		#include "BIT_MATH.h"
		#include "ATMEGA32_REG.h"

		/* MCAL */
		#include "UART_interface.h"
		
		
		
void UART_init(void)
{
/*
//Generic way to write on UCSRC:

u8 UCSRC_value;
//ENABLE WRITE ON UCSRC
SET_BIT(UCSRB,7);

CLR_BIT(UCSRB,0);

SET_BIT(UCSRB,1);
SET_BIT(UCSRB,2);

CLR_BIT(UCSRB,3);
CLR_BIT(UCSRB,4);

CLR_BIT(UCSRB,5);

CLR_BIT(UCSRB,6);

UCSRC = UCSRC_value;
 */	

/* Set >>>  [ 8N1 ] Standard:

USART Mode => Asynchronous Operation
Parity Mode => Disabled
Stop Bits => 1-bit
Character Size => 8-bit
*/

CLR_BIT(UCSRB,2);	
UCSRC = 0x86;  //0b10000110      

//Set Baud Rate --> 9600 
UBRRL = 103;
	
//ENABLE Tx
SET_BIT(UCSRB,3);
//ENABLE Rx
SET_BIT(UCSRB,4);	
}

void UART_TxChar(u8 Data)
{		
UDR = Data;
//WAIT until Data Register is Empty	
while(GET_BIT(UCSRA,5) == 0);
}

void UART_RxChar(u8* Data)
{
	if (Data != NULL)
	{
		//WAIT until USART Receive Complete
		while(GET_BIT(UCSRA,7) == 0);
		*Data = UDR;
	}
	
}



	/*Other Functions*/


void UART_TxString(u8* String)
{
	if (String != NULL)
	{
		u8 counter = 0;
		while(String[counter] != '\0')
		{
			UART_TxChar(String[counter]);
			counter++;
		}
	}
}


