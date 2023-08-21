/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Mohamed Nabil
 *
 ******************************************
 ******************************************
 * Application code example to test FIFO Buffer driver
 */

#include"FIFO.h"


#define length_1 5

item_type buffer1 [length_1];

int main(void){

	item_type i,temp;
	FIFO_Buf_t UART_fifo;

	//Initialization of fifo buffer
	FIFO_init(&UART_fifo,buffer1,length_1);

	//this should tell its empty
	FIFO_print_items(&UART_fifo);

	//loop test (should add 7 items if possible)
	for(i=0;i<7;i++){

		if(FIFO_enqueue(&UART_fifo,i)== FIFO_no_error)
			printf("\nFIFO Enqueue (%d) ---- Done\n",i);
		else
			printf("\n** FIFO_ERROR **\n");
	}

	printf("\n*********************\n");

	//loop test (should get 3 items if possible)
	for(i=0;i<3;i++){

		if(FIFO_dequeue(&UART_fifo,&temp)== FIFO_no_error)
			printf("\nFIFO Dequeue (%d) ---- Done\n",temp);
		else
			printf("\n** FIFO_ERROR **\n");
	}


	printf("\n*********************\n");

	//add new items
	if(FIFO_enqueue(&UART_fifo,22)== FIFO_no_error)
		printf("\nFIFO Enqueue (%d) ---- Done\n",22);
	else
		printf("\n** FIFO_ERROR **\n");

	if(FIFO_enqueue(&UART_fifo,33)== FIFO_no_error)
		printf("\nFIFO Enqueue (%d) ---- Done\n",33);
	else
		printf("\n** FIFO_ERROR **\n");


	printf("\n*********************\n");

	//print all items
	FIFO_print_items(&UART_fifo);



	return 0;
}


