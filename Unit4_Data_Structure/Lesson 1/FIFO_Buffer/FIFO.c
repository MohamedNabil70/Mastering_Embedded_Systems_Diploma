/*
 * FIFO.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Mohamed Nabil
 */


#include"FIFO.h"


/*initialize FIFO buffer */
FIFO_Buf_status FIFO_init(FIFO_Buf_t* fifo, item_type* buf,item_type length){

	//check for FIFO existence
	if(!fifo)
		return FIFO_null;

	//check for Buffer existence
	else if(!buf)
		return FIFO_no_buffer;

	//initialize the FIFO buffer
	else{

		fifo->Base = buf ;
		fifo->Head = buf ;
		fifo->Tail = buf ;
		fifo->Length = length ;
		fifo->Count = 0 ;

		return FIFO_no_error;
	}

}



/*Add an item to FIFO buffer */
FIFO_Buf_status FIFO_enqueue(FIFO_Buf_t* fifo, item_type item){

	//check for FIFO existence
	if(!fifo ||!fifo->Base ||!fifo->Head||!fifo->Tail)
		return FIFO_null;

	//Check if FIFO is full
	if(fifo->Count == fifo->Length)
		return FIFO_full;

	//Add an item to FIFO buffer


	//circular Buffer
	if(fifo->Head == (fifo->Base + (fifo->Length) * sizeof(item_type) ) ){

		fifo->Head = fifo->Base;
		*(fifo->Head)= item;
		fifo->Head++ ;
		fifo->Count++;
		return FIFO_no_error;

	}else{
		*(fifo->Head)= item;
		fifo->Head++ ;
		fifo->Count++;
		return FIFO_no_error;
	}
}

/*Get an item to FIFO buffer */
FIFO_Buf_status FIFO_dequeue(FIFO_Buf_t* fifo, item_type* item){

	//check for FIFO existence
	if(!fifo ||!fifo->Base ||!fifo->Head||!fifo->Tail)
		return FIFO_null;

	//Check if FIFO is empty
	if(!fifo->Count)
		return FIFO_empty;


	//circular Buffer
	if(fifo->Tail == (fifo->Base + (fifo->Length) * sizeof(item_type) ) ){

		//place tail at base first then get the item
		fifo->Tail = fifo->Base;
		*item = *(fifo->Tail);
		fifo->Tail++;
		fifo->Count--;

	}else{

		//Get first item into FIFO buffer
		*item = *(fifo->Tail);
		fifo->Tail++;
		fifo->Count--;

	}
	return FIFO_no_error;
}


void FIFO_print_items(FIFO_Buf_t* fifo){

	uint32_t c;
	item_type* temp= fifo->Tail;

	//check for FIFO existence
	if(!fifo ||!fifo->Base ||!fifo->Head||!fifo->Tail)
		printf("\n*** FIFO NULL ***\n");

	//Check if FIFO is empty
	if(!fifo->Count)
		printf("\n*** FIFO IS EMPTY ***\n");


	else
		printf("\n======= FIFO PRINT =======\n");
	for(c=0; c < fifo->Count ;c++){
		//circular Buffer
		if( temp == (fifo->Base + (fifo->Length) * sizeof(item_type) ) ){
			//place temp pointer at base first then get the item
			temp = fifo->Base;
			printf("\nitem #%d: %d \n",c+1,*temp);
			temp++;
		}else{
			printf("\nitem #%d: %d \n",c+1,*temp);
			temp++;
		}
	}
}
