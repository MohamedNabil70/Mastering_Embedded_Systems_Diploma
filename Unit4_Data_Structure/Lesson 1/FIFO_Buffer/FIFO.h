/*
 * FIFO.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Mohamed Nabil
 *
 *      This is a FIFO buffer driver containing main
 *  	circular FIFO Buffer functions
 */

#ifndef FIFO_H_
#define FIFO_H_

//includes
#include <stdio.h>
#include <stdint.h>


/******** User configuration ********/

//Choose item type (uint8_t , uint16_t , uint32_t ,.....)
#define item_type uint16_t


//when defining a buffer use the item_type
// #define length_1 5
// item_type buffer1 [length_1];


/******** Data types ********/

typedef struct{
	item_type* Base;
	item_type* Head;
	item_type* Tail;
	uint32_t Length;
	uint32_t Count;

}FIFO_Buf_t;

typedef enum{
	FIFO_no_error,
	FIFO_full,
	FIFO_null,
	FIFO_no_buffer,
	FIFO_empty
}FIFO_Buf_status;


/******** FIFO APIs ********/


/*initialize FIFO buffer */
FIFO_Buf_status FIFO_init(FIFO_Buf_t* fifo, item_type* buf,item_type length);

/*Add an item to FIFO buffer */
FIFO_Buf_status FIFO_enqueue(FIFO_Buf_t* fifo, item_type item);

/*Get an item to FIFO buffer */
FIFO_Buf_status FIFO_dequeue(FIFO_Buf_t* fifo, item_type* item);

/*Prints all content of FIFO buffer*/
void FIFO_print_items(FIFO_Buf_t* fifo);




#endif /* FIFO_H_ */
