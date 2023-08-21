/*
 * linked_list_database.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Mohamed Nabil
 */

#ifndef LINKED_LIST_DATABASE_H_
#define LINKED_LIST_DATABASE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/******** Module Data types ********/

typedef struct{

	char name[40] ;
	uint32_t ID;
	float height;

}Sdata;

struct Sstudent{

	Sdata student;
	struct Sstudent* pNextStudent;

};

typedef struct Sstudent Snode_t;

typedef enum{
	No_error,
	Full,
	empty,
	failed,
}Operation_status;

typedef enum{
	AddStudent = 1,DeleteStudent,PrintStudents,
	DeleteAllStudents,PrintStudentsNum,GetNthStudent,
	GetMidStudent,GetNthFromEnd,ReverseStudents,Exit
}Database_Options;


/******** Module APIs ********/

//Options functions :

/*Used to add a new student to your database*/
void Add_Student();

/*Used to delete a student from your database using his id*/
void Delete_Student();

/*Used to Display all students in the Database */
void Print_Students();

/*Used to delete all students in the Database */
void Delete_All_Students();

/*Used to Display the number of students in the Database*/
void Print_Students_Num();

/*Used to Display the Nth (user is asked to enter the number) student in the Database from the beginning*/
void Get_Nth_Student();

/*Used to Display the middle student data in the Database*/
void Get_Mid_Student();

/*Used to Display the Nth (user is asked to enter the number) student in the Database from the end*/
void Get_Nth_From_End();

/*Used to reverse the order of the students data in the Database*/
void Reverse_Students();



//Additional functions :


/*Prints all Database options*/
void Print_Options();

/*This function takes a new record (newStudent) in order to
 *  fill it by user interface*/
Operation_status Fill_the_record(Snode_t* newStudent);

/*This function takes a student node and his index in order to print it*/
void Print_Data_Of(Snode_t* pCurrentStudent, uint32_t count);

/*Checks if Database is empty*/
Operation_status DatabaseIsEmpty();




#endif /* LINKED_LIST_DATABASE_H_ */
