/*
 * main.c
 *
 *  Created on: Sep 4, 2023
 *      Code By: Mohamed Nabil Mohamed
 *
 *      [This is an application code example to test queue student database driver]
 */


/******** Includes ********/
#include "queue_student_database.h"

/******** Global Variables ********/

//this is the database buffer

extern FIFO_Buf_t Database_queue;
extern sDataBlock st[MAX_STUDENT_NUM];

/******** Application Functions ********/
void setup(){


	//Initialization of Database FIFO buffer
	if(FIFO_init(&Database_queue,st,MAX_STUDENT_NUM) != FIFO_no_error)
		printf("\n[ERROR] ** FIFO_ERROR **\n");



	printf("\n==========*==========================================*==========\n");
	printf("========= | Welcome to the Student Management System | =========\n");
	printf("==========*==========================================*==========\n");


	printf("\n\t*======================================*\n");

	printf("\n\t[INFO] You Can Add Up To %d Students & Up To %d Course IDs For Each One\n",MAX_STUDENT_NUM,5);

	printf("\n\t*======================================*\n");
	printf("\n\t[IMPORTANT NOTE] Steps Required To Use Option [2] In The System.");
	printf("\n\t[IMPORTANT NOTE] These Steps Should Be Followed For The Option To Work Correctly:");

	printf("\n\t The file should have the following details:");
	printf("\n\t1- File Name should be : student_info.txt");
	printf("\n\t2- File should be stored at the same folder with project .c files or .exe files");
	printf("\n\t3- the data order in each line should be as follows:");
	printf("\n\tRollNumber FirstName LastName GPA Course_1_ID Course_2_ID Course_3_ID Etc");
	printf("\n\t#Examples of a line:");
	printf("\n\t 1 Mohamed Nabil 3.9 1 2 3 4 5");
	printf("\n\t 2 Mostafa Lotfy 4.0 5 2 3 4 6\n");

	printf("\n[WARNING] NUMBER OF STUDENTS IN .txt FILE MUST NOT EXCEED\n"
		     "          THE MAXIMUM NUMBER ALLOWED IN DATABASE.");
	printf("\n\t*======================================*\n");
}



/******** Main Function ********/
int main(void){

	//To select an option in database
	Database_Options option;
	char temp_cahr[30];


	//To solve I/O buffer bug in Eclipse
	setbuf(stdout,NULL);


	//initializing database
	setup();



	//Super Loop
	while(1){

		//Take option from the user
		Print_Options();
		gets(temp_cahr);
		option=atoi(temp_cahr);
		printf("\n==================================================\n");


		//Perform selected option
		switch(option){

		case Add_student_manually:

			add_student_manually(&Database_queue);

			break;

		case Add_student_file:

			add_student_file(&Database_queue);
			break;

		case Find_rl:

			find_rl(&Database_queue);

			break;

		case Find_fl:

			find_fn(&Database_queue);

			break;

		case Find_c:

			find_c(&Database_queue);

			break;

		case Tot_s:

			tot_s(&Database_queue);

			break;

		case Del_s:

			del_s(&Database_queue);

			break;

		case Up_s:

			up_s(&Database_queue);

			break;

		case Show_s:

			show_s(&Database_queue);

			break;

		case Exit:

			break;


		default:
			printf("\n=== INVALID OPTION, TRY AGAIN ===\n");
			break;


		}

		if(option == Exit){
			printf("\n#===****### END OF PROGRAM ###****===#\n");
			break;
		}

	}



	return 0;
}
