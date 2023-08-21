/*
 * LIFO.c
 *
 *  Created on: Aug 13, 2023
 *     Author: Mohamed Nabil
 *
 */

#include "LIFO.h"


LIFO_Buf_status LIFO_init(LIFO_Buf_t* lifo, item_type* buf,item_type length)
{

	//check for buffer existence
	if(lifo == NULL)
		return LIFO_null;
	if(buf == NULL)
		return LIFO_no_buffer;

    //initialize LIFO buffer
	lifo->Base = buf;
	lifo->Head = buf;
	lifo->Length = length;
	lifo->count = 0;
	return LIFO_no_error;


}

LIFO_Buf_status LIFO_add_item(LIFO_Buf_t* lifo, item_type item){

	//check for buffer existence
	if(lifo == NULL || lifo->Head == NULL || lifo->Base == NULL)
		return LIFO_null;

	//check if buffer is full
	if(lifo->count == lifo->Length)
		return LIFO_full;

	//Add new item to buffer
	*(lifo->Head) =item;
	lifo->Head++ ;
	lifo->count++ ;
	return LIFO_no_error;


}

LIFO_Buf_status LIFO_get_itm(LIFO_Buf_t* lifo, item_type* item){

	//check for buffer existence
	if(lifo == NULL || lifo->Head == NULL || lifo->Base == NULL)
		return LIFO_null;

	//check if buffer is empty
	if(lifo->count == 0)
		return LIFO_empty;

	//get last item from buffer top
	lifo->Head--;
	*item = *(lifo->Head);
	lifo->count-- ;
	return LIFO_no_error;

}
