#include "UART.h"

#define UART0_BASE (unsigned int*)0x101f1000
#define UART0DR *((volatile unsigned int* const)(UART0_BASE + 0x0))

//const int x=3; .rodata test

void UART_Send_string(unsigned char* P_tx_string)
{
	
	while(*P_tx_string != '\0')     //loop until end of string
	{
		
		UART0DR = (unsigned int) *P_tx_string;	 //transmit character 
		P_tx_string++ ;
	}
	
}