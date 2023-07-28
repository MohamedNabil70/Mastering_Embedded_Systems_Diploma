#include "UART.h"


unsigned char string_buffer[100] = "learn-in-depth: <Mohamed Nabil>";

int main(void)
{
	UART_Send_string(string_buffer);
	
	
	return 0;
}