/*
 * main.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Mohamed Nabil
 *
 *      Application code example to test linked list database driver
 */

#include"linked_list_database.h"

int main(void){

	char temp_cahr[25];

	//To solve I/O buffer bug in eclipse
	setbuf(stdout,NULL);

	//To select an option
	Database_Options option;

	//Infinite Loop
	while(1){

		//receiving option from user
		Print_Options();
		gets(temp_cahr);
		option=atoi(temp_cahr);
		printf("\n===================================\n");



		switch(option){

		case AddStudent:

			Add_Student();

			break;

		case DeleteStudent:

			Delete_Student();
			break;

		case PrintStudents:

			Print_Students();

			break;

		case DeleteAllStudents:

			Delete_All_Students();

			break;

		case PrintStudentsNum:

			Print_Students_Num();

			break;

		case GetNthStudent:

			Get_Nth_Student();

			break;

		case GetMidStudent:

			Get_Mid_Student();

			break;

		case GetNthFromEnd:

			Get_Nth_From_End();

			break;

		case ReverseStudents:

			Reverse_Students();

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
