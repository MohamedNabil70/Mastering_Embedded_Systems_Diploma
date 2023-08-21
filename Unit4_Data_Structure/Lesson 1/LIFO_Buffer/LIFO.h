/*
 * LIFO.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Mohamed Nabil
 *
 *      This is a LIFO buffer driver containing main
 *  	LIFO Buffer functions
 */

#ifndef LIFO_H_
#define LIFO_H_

//includes
#include <stdio.h>
#include <stdint.h>


/******** User configuration ********/

//Choose item type (uint8_t , uint16_t , uint32_t ,.....)
#define item_type uint32_t


//when defining a buffer use the item_type
// #define length_1 5
// item_type buffer1 [length_1];


/******** Data types ********/

typedef struct{
	item_type* Base;
	item_type* Head;
	item_type Length;
	item_type count;

}LIFO_Buf_t;

typedef enum{
	LIFO_no_error,
	LIFO_full,
	LIFO_null,
	LIFO_no_buffer,
	LIFO_empty
}LIFO_Buf_status;


/******** LIFO APIs ********/


/*initialize LIFO buffer */
LIFO_Buf_status LIFO_init(LIFO_Buf_t* lifo, item_type* buf,item_type length);

/*Add an item to LIFO buffer */
LIFO_Buf_status LIFO_add_item(LIFO_Buf_t* lifo, item_type item);

/*Get an item to LIFO buffer */
LIFO_Buf_status LIFO_get_itm(LIFO_Buf_t* lifo, item_type* item);




#endif /* LIFO_H_ */
