/*
 * queue_student_database.h
 *
 *  Created on: Sep 4, 2023
 *      Code By: Mohamed Nabil Mohamed
 *
 * [ This is a FIFO (First in First out) buffer student database containing
 *   main circular FIFO Buffer functions ]
 */

#ifndef QUEUE_STUDENT_DATABASE_H_
#define QUEUE_STUDENT_DATABASE_H_

/******** Includes ********/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/******** Configurable data (#define) ********/

//Configure Database size (max number of students available)
// [system Memory limits should be considered]
#define MAX_STUDENT_NUM 50

//Configure the max number of course IDs that each student has
// [system Memory limits should be considered]



//when defining a buffer use the sDataBlock
// #define length_1 5
// sDataBlock buffer1 [length_1];

/******** Data types ********/

//this is the single unit  forming database
typedef struct sinfo{

	char fname[50] ;
	char lname[50] ;
	uint32_t roll;
	float GPA;
	uint32_t cid[5];

}sDataBlock;

typedef struct{
	sDataBlock* Base;
	sDataBlock* Head;
	sDataBlock* Tail;
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

typedef enum{
FALSE,
TRUE
}Check_status;




typedef enum{
	Add_student_manually = 1,Add_student_file,Find_rl,
	Find_fl,Find_c,Tot_s,Del_s,Up_s,Show_s,Exit

}Database_Options;




/******** Module APIS ********/

/*   FIFO APIs   */

/*initialize FIFO buffer */
FIFO_Buf_status FIFO_init(FIFO_Buf_t* fifo, sDataBlock* buf,uint32_t length);

/*Add an item to FIFO buffer */
FIFO_Buf_status FIFO_enqueue(FIFO_Buf_t* fifo, sDataBlock NewRecord);

/*Get an item from FIFO buffer */
FIFO_Buf_status FIFO_dequeue(FIFO_Buf_t* fifo, sDataBlock* Destination);

/*Checks if Fifo is Full or not*/
Check_status FIFO_isFull(FIFO_Buf_t* fifo);

/*Checks if Fifo is Empty or not*/
Check_status FIFO_isEmpty(FIFO_Buf_t* fifo);

/*Prints all content of FIFO buffer*/
void FIFO_print_items(FIFO_Buf_t* fifo);

/*   Student Database APIs  */

//Options functions :

/*Used to add a new student to your database manually*/
void add_student_manually(FIFO_Buf_t* fifo);

/*Used to add a new student to your database from a given text file*/
void add_student_file(FIFO_Buf_t* fifo);

/*Used to find student details using unique roll number*/
void find_rl(FIFO_Buf_t* fifo);

/*Used to find student details using his first name*/
void find_fn(FIFO_Buf_t* fifo);

/*Used to find all students signed to a course using course ID*/
void find_c(FIFO_Buf_t* fifo);

/*Used to display total number of students*/
void tot_s(FIFO_Buf_t* fifo);

/*Used to delete student details using his unique roll number*/
void del_s(FIFO_Buf_t* fifo);

/*Used to update student details using his unique roll number*/
void up_s(FIFO_Buf_t* fifo);

/*Used to display all student details in the database*/
void show_s(FIFO_Buf_t* fifo);


//Additional functions :


/*Prints all Database options*/
void Print_Options();

/*This function takes a new record (newStudent) in order to
 *  fill it by user interface*/
Check_status Fill_the_record(sDataBlock* newStudent);

/*This function takes a student node in order to print it*/
void Print_Data_Of(sDataBlock* Student);

/*Checks if Student Roll given Is Taken or not*/
Check_status StudentRollIsTaken(FIFO_Buf_t* fifo,uint32_t roll);




#endif /* QUEUE_STUDENT_DATABASE_H_ */
