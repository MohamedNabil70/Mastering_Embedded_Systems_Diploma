/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Mohamed Nabil
 *
 *
 */


#include "LIFO.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define length_1 5
#define length_2 6

item_type buffer1 [length_1];

int main(){
	item_type i, temp;
	LIFO_Buf_t UART_lifo,I2C_lifo;
	//create buffer 2 (Dynamic allocation)
	item_type* buffer2 =(item_type*)malloc(length_2 * sizeof(item_type));

	LIFO_init(&UART_lifo,buffer1,length_1);
	LIFO_init(&I2C_lifo,buffer2,length_2);

	for(i=0;i<length_1;i++){
		if(LIFO_add_item(&UART_lifo,i)== LIFO_no_error)
		printf("\nUART_lifo add item : %d\n",i);
		else
			printf("\nLIFO_error\n");
	}

	printf("\n****************\n");

	for(i=0;i<length_1;i++){
		if(LIFO_get_itm(&UART_lifo,&temp) == LIFO_no_error)
		printf("\nUART_lifo get item : %d\n",temp);
		else
			printf("\nLIFO_error\n");
	}









	return 0;
}
