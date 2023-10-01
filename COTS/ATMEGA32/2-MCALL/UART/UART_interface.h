/*
 * UART_interface.h
 *
 * Created: 10/4/2022 9:35:07 AM
 *  Author: Mohamed Nabil
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_




	/*Main Functions*/
	
void UART_init(void);
void UART_TxChar(u8 Data);
void UART_RxChar(u8* Data);

	/*Other Functions*/
void UART_TxString(u8* String);


#endif /* UART_INTERFACE_H_ */