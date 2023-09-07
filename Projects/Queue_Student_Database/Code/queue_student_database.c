/*
 * queue_student_database.c
 *
 *  Created on: Sep 4, 2023
 *      Code By: Mohamed Nabil Mohamed
 */


/******** Includes ********/

#include "queue_student_database.h"


/******** Global Variables ********/

//this is the database buffer

FIFO_Buf_t Database_queue;
sDataBlock st[MAX_STUDENT_NUM];

/******** Functions Implementation ********/


//======================================================
/********* Queue Functions *********/


/****************************
 * Function Name:FIFO_init
 * Function Use:Initialize FIFO buffer
 * Inputs (Arguments):fifo->  (pointer to the new fifo),
 * 					  buf->   (pointer to the buffer to attach to fifo) ,
 * 					  length->(required length for the new created fifo buffer)
 * Output (Return): FIFO buffer status as an enumeration
 *
 * **************************/
FIFO_Buf_status FIFO_init(FIFO_Buf_t* fifo, sDataBlock* buf,uint32_t length){

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


/****************************
 * Function Name:FIFO_enqueue
 * Function Use:Adds a new record to FIFO buffer (queue)
 * Inputs (Arguments):fifo->     (pointer to the fifo),
 * 					  NewRecord->(the new record to be add to queue)
 * Output (Return): FIFO buffer status as an enumeration
 *
 * **************************/
FIFO_Buf_status FIFO_enqueue(FIFO_Buf_t* fifo, sDataBlock NewRecord){

	//check for FIFO existence
	if(!fifo ||!fifo->Base ||!fifo->Head||!fifo->Tail)
		return FIFO_null;

	//Check if FIFO is full
	if(fifo->Count == fifo->Length)
		return FIFO_full;

	//Add record to FIFO circular Buffer

	//Check if head is at last position
	if(fifo->Head == (fifo->Base + (fifo->Length) * sizeof(sDataBlock) ) ){

		fifo->Head = fifo->Base;
		*(fifo->Head)= NewRecord;
		fifo->Head++ ;
		fifo->Count++;
		return FIFO_no_error;

	}else{
		*(fifo->Head)= NewRecord;
		fifo->Head++ ;
		fifo->Count++;
		return FIFO_no_error;
	}
}


/****************************
 * Function Name:FIFO_dequeue
 * Function Use:Gets a record from FIFO buffer
 * Inputs (Arguments):fifo-> 	   (pointer to the fifo),
 * 					  Destination->(pointer to sDataBlock that will carry the dequeued record)
 * Output (Return): FIFO buffer status as an enumeration
 *
 * **************************/
FIFO_Buf_status FIFO_dequeue(FIFO_Buf_t* fifo, sDataBlock* Destination){

	//check for FIFO existence
	if(!fifo ||!fifo->Base ||!fifo->Head||!fifo->Tail)
		return FIFO_null;

	//Check if FIFO is empty
	if(!fifo->Count)
		return FIFO_empty;


	//circular Buffer
	if(fifo->Tail == (fifo->Base + (fifo->Length) * sizeof(sDataBlock) ) ){

		//place tail at base first then get the record
		fifo->Tail = fifo->Base;
		*Destination = *(fifo->Tail);
		fifo->Tail++;
		fifo->Count--;

	}else{

		//Get first record into FIFO buffer
		*Destination = *(fifo->Tail);
		fifo->Tail++;
		fifo->Count--;

	}
	return FIFO_no_error;
}


/****************************
 * Function Name:FIFO_isFull
 * Function Use:Checks if Fifo is Full or not
 * Inputs (Arguments):fifo->(pointer to the fifo you want to check),
 * Output (Return):         (FIFO buffer status as an enumeration)
 *
 * **************************/
Check_status FIFO_isFull(FIFO_Buf_t* fifo){

	//Check if FIFO is full
	if(fifo->Count == fifo->Length)
		return TRUE;
	else
		return FALSE;

}


/****************************
 * Function Name:FIFO_isEmpty
 * Function Use:Checks if Fifo is Empty or not
 * Inputs (Arguments):fifo->(pointer to the fifo you want to check),
 * Output (Return):         (FIFO buffer status as an enumeration)
 *
 * **************************/
Check_status FIFO_isEmpty(FIFO_Buf_t* fifo){
	//Check if FIFO is empty
	if(!fifo->Count)
		return TRUE;
	else
		return FALSE;
}


/****************************
 * Function Name:FIFO_print_items
 * Function Use:Prints all content of FIFO buffer
 * Inputs (Arguments):
 * Output (Return):[NOTHING]
 *
 * **************************/
void FIFO_print_items(FIFO_Buf_t* fifo){

	uint32_t c;
	sDataBlock* temp= fifo->Tail;

	//check for FIFO existence
	if(!fifo ||!fifo->Base ||!fifo->Head||!fifo->Tail)
		printf("\n*** Queue is not found create one first ***\n");

	//Check if FIFO is empty
	else if(!fifo->Count)
		printf("\n*** Queue IS EMPTY ***\n");

	else{
		printf("\n======= Queue PRINT =======\n");

		for(c=0; c < fifo->Count ;c++){
			//circular Buffer
			if(temp == (fifo->Base + (fifo->Length) * sizeof(sDataBlock) ) ){

				//place temporary pointer at base first then get the record
				temp = fifo->Base;
				printf("\n ======== #%d ========\n",c+1);
				Print_Data_Of(temp);
				temp++;

			}else{
				printf("\n ======== #%d ========\n",c+1);
				Print_Data_Of(temp);
				temp++;
			}
		}
	}
}





/************ Student Database Functions ************/





//Options functions :


/****************************
 * Function Name: add_student_manually
 * Function Use:Used to add a new student to your database manually
 * Inputs (Arguments): fifo->(Pointer to the fifo you want add student to)
 * Output (Return): [NOTHING]
 *
 * **************************/
void add_student_manually(FIFO_Buf_t* fifo){

	sDataBlock NewStudent;

	//Check if FIFO is full
	if(FIFO_isFull(fifo)){
		printf("\n[ERROR] Database is full");
		tot_s(fifo);
	}else{

		//check if Roll Number is taken then proceed
		if(!Fill_the_record(&NewStudent))
			printf("\n[ERROR] Roll Number %d Is Already Taken",NewStudent.roll);
		else{

			//add new record to Database queue
			FIFO_enqueue(fifo,NewStudent);
			printf("\n[INFO] Student Details Are Added Successfully");
		}

	}

}


/****************************
 * Function Name: add_student_file
 * Function Use: Add a new student to your database from a given text file
 * 				 (The text file should be in the same folder with the .exe file)
 * Inputs (Arguments):fifo->(Pointer to the fifo you want add student to)
 * Output (Return):[NOTHING]
 *
 * **************************/
void add_student_file(FIFO_Buf_t* fifo){

	uint32_t StudentCount = fifo->Count;
	FILE *file;
	char line[100] , stat_flag = 0;

	file = fopen("student_info.txt", "r");


	if (file == NULL) {
		printf("\n[ERROR] Unable to open the file.");
		printf("\n[INFO] The file should have the following details:");
		printf("\n\t1- File Name should be : student_info.txt");
		printf("\n\t2- File should be stored at the same folder with project .c files or .exe files");
		printf("\n\t3- the data order in each line should be as follows:");
		printf("\n\tRollNumber FirstName LastName GPA Course_1_ID Course_2_ID Course_3_ID Etc");
		printf("\n\t#Examples of a line:");
		printf("\n\t 1 Mohamed Nabil 3.9 1 2 3 4 5");
		printf("\n\t 2 Mostafa Lotfy 4.0 5 2 3 4 6\n");

		printf("\n[WARNING] NUMBER OF STUDENTS IN .txt FILE MUST NOT EXCEED\n"
				"          THE MAXIMUM NUMBER ALLOWED IN DATABASE.");
		printf("\n\t-----------------\n");
		return;
	}else{


		// Create a structure to receive data in
		sDataBlock student;

		printf("\n[INFO] FILE READING STATUS :\n");

		while(fgets(line, sizeof(line), file) != NULL){

			// Use sscanf to parse the line and store values in the structure
			sscanf(line, "%d %s %s %f %d %d %d %d %d",
					&student.roll, student.fname, student.lname,
					&student.GPA, &student.cid[0], &student.cid[1],
					&student.cid[2], &student.cid[3], &student.cid[4]);

			//Check if roll is taken
			if(StudentRollIsTaken(fifo,student.roll))
				printf("\n[ERROR] Roll Number %d Is Not Added Again [Already Taken]",student.roll);

			else if(StudentCount < fifo->Length){
				FIFO_enqueue(fifo,student);
				printf("\n[INFO] Roll Number %d Saved Successfully",student.roll);
				//update status flag
				stat_flag = 1;

				//update StudentCount
				StudentCount++;
			}else{
				printf("\n[ERROR] Roll Number %d Is Not Added [DATABASE IS FULL]",student.roll);
			}

		}

		printf("\n\n-------------------------");
		if(stat_flag)
			printf("\n[INFO] Student Details Are Added Successfully.");
		else
			printf("\n[ERROR] Student Details Are Not Added");


		tot_s(fifo);

	}




}


/****************************
 * Function Name:find_rl
 * Function Use:Find student details using his unique roll number
 * Inputs (Arguments):fifo->(Pointer to the fifo you want to check)
 * Output (Return):[NOTHING]
 *
 * **************************/
void find_rl(FIFO_Buf_t* fifo){

	//Check if FIFO is Empty
	if(FIFO_isEmpty(fifo)){
		printf("\n[ERROR] Database Is Empty");
	}else{

		char temp_char [20];
		uint32_t i , selected_roll,rollIsFound =0;
		sDataBlock* pTemp = fifo->Tail;


		printf("\nEnter the roll number of the student:");
		gets(temp_char);
		selected_roll = atoi(temp_char);

		//loop on all available Student records
		for(i = 0 ;i < fifo->Count ; i++,pTemp++){

			//pTemp check considering circular FIFO (in case of reaching upper limit)
			if(pTemp == (fifo->Base + (fifo->Length) * sizeof(sDataBlock) ) )
				pTemp = fifo->Base;

			if(selected_roll == pTemp->roll){

				//Print status
				printf("\n[INFO] Student Found.");
				printf("\nThe student details are:");

				Print_Data_Of(pTemp);

				//update roll found flag
				rollIsFound++;
			}

		}

		if(!rollIsFound)
			//Print status
			printf("\n[ERROR] Roll Number [ %d ] Not Found..",selected_roll);

	}
}


/****************************
 * Function Name:find_fn
 * Function Use:Find student details using his first name
 * Inputs (Arguments):fifo->(Pointer to the fifo you want to check)
 * Output (Return):[NOTHING]
 *
 * **************************/
void find_fn(FIFO_Buf_t* fifo){

	//Check if FIFO is Empty
	if(FIFO_isEmpty(fifo)){
		printf("\n[ERROR] Database Is Empty");
	}else{

		char selected_name[50];
		uint32_t i,found=0;
		sDataBlock* pTemp = fifo->Tail;


		printf("\nEnter The First Name Of Student : ");
		gets(selected_name);

		//loop on all available Student records
		for(i=0; i < fifo->Count ; i++,pTemp++){

			//pTemp check considering circular FIFO (in case of reaching upper limit)
			if(pTemp == (fifo->Base + (fifo->Length) * sizeof(sDataBlock) ) )
				pTemp = fifo->Base;

			if(!stricmp(selected_name,pTemp->fname)){

				printf("\n....................");
				printf("\n[INFO] Student Found.");
				printf("\nThe student details are:");

				Print_Data_Of(pTemp);

				//update found flag
				found++;
			}

		}

		//Print status
		if(!found)
			printf("\n[ERROR] First Name [ %s ] Not Found..",selected_name);

	}
}


/****************************
 * Function Name:find_c
 * Function Use: Find all students signed to a course using course ID
 * Inputs (Arguments): fifo->(Pointer to the fifo you want to check)
 * Output (Return): [NOTHING]
 *
 * **************************/
void find_c(FIFO_Buf_t* fifo){

	//Check if FIFO is Empty
	if(FIFO_isEmpty(fifo)){
		printf("\n[ERROR] Database Is Empty");
	}else{

		char temp_char [20];
		uint32_t i, j , count = 0, selected_ID;
		sDataBlock* pTemp = fifo->Tail;


		printf("\nEnter the course ID:");
		gets(temp_char);
		selected_ID = atoi(temp_char);

		//loop on all available Student records
		for(i=0; i < fifo->Count ;i++,pTemp++){

			//pTemp check considering circular FIFO (in case of reaching upper limit)
			if(pTemp == (fifo->Base + (fifo->Length) * sizeof(sDataBlock) ) )
				pTemp = fifo->Base;

			//loop on all available course IDs
			for(j=0; j < 5 ;j++){

				if(selected_ID == pTemp->cid[j]){

					printf("\nThe student details are:");
					Print_Data_Of(pTemp);
					printf("\n---");

					//increment count
					count++;
					break;
				}

			}


		}

		//Print status
		if(count)
			printf("\n[INFO] Total Number Of Students Enrolled: %d ",count);
		else
			printf("\n[ERROR] Course ID [ %d ] Not Found..",selected_ID);


	}
}


/****************************
 * Function Name:tot_s
 * Function Use:Used to display total number of students in the Database
 * Inputs (Arguments): fifo->(Pointer to the fifo you want to check)
 * Output (Return): [NOTHING]
 *
 * **************************/
void tot_s(FIFO_Buf_t* fifo){

	//Check if FIFO is Empty
	if(FIFO_isEmpty(fifo)){
		printf("\n[INFO] Database Is Empty (Total Number Of Students is 0)");
	}else{

		//Print status
		printf("\n-----------------------------");
		printf("\n[INFO] The Total Number Of Students is: %d",fifo->Count);
		printf("\n[INFO] You Can Add Up To %d Students",MAX_STUDENT_NUM);
		printf("\n[INFO] You Can Add %d More Students",(MAX_STUDENT_NUM - (fifo->Count)));

	}
}


/****************************
 * Function Name:del_s
 * Function Use:Used to delete student details using his unique roll number
 * Inputs (Arguments): fifo->(Pointer to the fifo you want to check)
 * Output (Return): [NOTHING]
 *
 * **************************/
void del_s(FIFO_Buf_t* fifo){



	//Check if FIFO is Empty
	if(FIFO_isEmpty(fifo)){
		printf("\n[ERROR] Database Is Empty");
	}else{

		char temp_char [20];
		uint32_t i , selected_roll ,rollIsFound =0;
		sDataBlock* pTemp = fifo->Tail;


		printf("\nEnter The Roll Number Of The Student To Delete Details:");
		gets(temp_char);
		selected_roll = atoi(temp_char);

		//loop on all available Student records
		for(i = 0 ;i < fifo->Count ; i++,pTemp++){

			//pTemp Update considering circular FIFO (in case of reaching upper limit)
			if(pTemp == (fifo->Base + (fifo->Length) * sizeof(sDataBlock) ) )
				pTemp = fifo->Base;

			if(selected_roll == pTemp->roll){

				if(FIFO_dequeue(fifo,pTemp) == FIFO_no_error)
					printf("\n[INFO] Student Details Deleted Successfully.");
				else
					printf("\n[ERROR] Student Found but details couldn't be deleted.");

				//update student found flag
				rollIsFound++;
			}
		}

		if(!rollIsFound)
			//Print status
			printf("\n[ERROR] Roll Number [ %d ] Not Found..",selected_roll);

	}
}


/****************************
 * Function Name:up_s
 * Function Use:Used to update student details using his unique roll number
 * Inputs (Arguments): fifo->(Pointer to the fifo you want to check)
 * Output (Return): [NOTHING]
 *
 * **************************/
void up_s(FIFO_Buf_t* fifo){

	//Check if FIFO is Empty
	if(FIFO_isEmpty(fifo)){
		printf("\n[INFO] Database Is Empty");
	}else{
		char temp_char [20];
		uint32_t i , selected_roll,selected_option,rollIsFound =0;
		sDataBlock* pTemp = fifo->Tail;


		printf("\nEnter the roll number of the student:");
		gets(temp_char);
		selected_roll = atoi(temp_char);

		//loop on all available Student records
		for(i = 0 ;i < fifo->Count ; i++,pTemp++){

			//pTemp check considering circular FIFO (in case of reaching upper limit)
			if(pTemp == (fifo->Base + (fifo->Length) * sizeof(sDataBlock) ) )
				pTemp = fifo->Base;


			if(selected_roll == pTemp->roll){

				//Print Options
				printf("\n[INFO] Student Found.");
				printf("\nTWhat Would You Like To Update?");
				printf("\n\t1.First Name");
				printf("\n\t2.Last Name");
				printf("\n\t3.Roll Number");
				printf("\n\t4.GPA");
				printf("\n\t5.Courses\n");

				gets(temp_char);
				selected_option = atoi(temp_char);

				switch(selected_option){

				case 1:
					printf("\nEnter The First Name Of Student : ");
					gets(pTemp->fname);
					printf("\n[INFO] UPDATED SUCCESSFULLY.");
					break;

				case 2:
					printf("\nEnter The Last Name Of Student : ");
					gets(pTemp->lname);
					printf("\n[INFO] UPDATED SUCCESSFULLY.");
					break;

				case 3:
					printf("\nEnter The New Roll Number: ");
					gets(temp_char);

					//Check if roll number is taken
					if(StudentRollIsTaken(fifo,atoi(temp_char)))
						printf("\n[ERROR] Roll Number %d Is Already Taken",atoi(temp_char));
					else{
						pTemp->roll = atoi(temp_char);
						printf("\n[INFO] UPDATED SUCCESSFULLY.");
					}

					break;

				case 4:
					printf("\nEnter The GPA Of Student: ");
					gets(temp_char);
					pTemp->GPA = atof(temp_char);
					printf("\n[INFO] UPDATED SUCCESSFULLY.");
					break;

				case 5:
					printf("\nEnter The Course ID Of Each Course ");

					for(i=0;i<5;i++){

						printf("\nCourse %d ID: ",(i+1));
						gets(temp_char);
						pTemp->cid[i] = atoi(temp_char);

					}
					printf("\n[INFO] UPDATED SUCCESSFULLY.");
					break;

				default :
					printf("\n[ERROR] Wrong Option.\n (Choose from 1 to 5 next time..)");
					break;
				}

				//update roll status flag
				rollIsFound++;
				break;
			}

		}

		if(!rollIsFound)
			printf("\n[ERROR] Roll Number [ %d ] Not Found..",selected_roll);



	}
}


/****************************
 * Function Name:show_s
 * Function Use:Used to display all student details in the database
 * Inputs (Arguments): fifo->(Pointer to the fifo you want to check)
 * Output (Return): [NOTHING]
 *
 * **************************/
void show_s(FIFO_Buf_t* fifo){

	//Check if FIFO is Empty
	if(FIFO_isEmpty(fifo)){
		printf("\n[INFO] Database Is Empty");
	}else{

		FIFO_print_items(fifo);
		tot_s(fifo);
	}
}


//Additional functions :



/****************************
 * Function Name:Print_Options
 * Function Use:Prints All Database Options
 * Inputs (Arguments): [NOTHING]
 * Output (Return): [NOTHING]
 *
 * **************************/
void Print_Options(){
	printf("\n=========================================\n");
	printf("\t## Choose The Task That You Want To Perform ##\n\n");

	printf("  #1: Add New Student Manually\n");
	printf("  #2: Add New Student Using .text File\n");
	printf("  #3: Find Student Details By Roll Number \n");
	printf("  #4: Find Student Details By First Name\n");
	printf("  #5: Find Student Details By Course ID\n");
	printf("  #6: Find The Total Number Of Students \n");
	printf("  #7: Delete Student Details By Roll Number\n");
	printf("  #8: Update Student Details By Roll Number\n");
	printf("  #9: Show All Student Details In The System\n");
	printf(" #10: Exit\n");

	printf("\n----Enter Option Number: ");

}


/****************************
 * Function Name:Fill_the_record
 * Function Use:Takes a new record (newStudent) in order to
 *              fill it by user interface
 * Inputs (Arguments): *newStudent (pointer to new Student from type sDataBlock)
 * Output (Return): Database status as an enumeration
 *
 * **************************/
Check_status Fill_the_record(sDataBlock* newStudent){

	char temp_char[25];
	int i;

	printf("\nEnter The Roll Number: ");
	gets(temp_char);
	newStudent->roll = atoi(temp_char);

	//Check if roll is taken
	if(StudentRollIsTaken(&Database_queue,newStudent->roll))
		return FALSE;

	else{
		printf("Enter The First Name Of Student : ");
		gets(newStudent->fname);

		printf("Enter The Last Name Of Student : ");
		gets(newStudent->lname);

		printf("Enter The GPA Of Student: ");
		gets(temp_char);
		newStudent->GPA = atof(temp_char);

		printf("\nEnter The Course ID Of Each Course\n");

		for(i=0;i<5;i++){

			printf("Course %d ID: ",(i+1));
			gets(temp_char);
			newStudent->cid[i] = atoi(temp_char);

		}

		return TRUE;
	}


}


/****************************
 * Function Name:Print_Data_Of
 * Function Use:This function takes a student node and his index in order to print it
 * Inputs (Arguments):Student->(A pointer to the student DataBlock to print its Details)
 * Output (Return):[NOTHING]
 *
 * **************************/
void Print_Data_Of(sDataBlock* Student){

	int i;

	printf("\nStudent First Name: %s",Student->fname);
	printf("\nStudent Last Name: %s",Student->lname);
	printf("\nStudent Roll Number: %d",Student->roll);
	printf("\nStudent GPA Number: %.2f",Student->GPA);

	for(i=0;i < 5 ;i++){
		printf("\nCourse %d ID: %d",(i+1),Student->cid[i]);
	}

}


/****************************
 * Function Name: StudentRollIsTaken
 * Function Use: Checks if Student Roll given Is Taken in Database_queue or not
 * Inputs (Arguments):fifo->(Pointer to the fifo you want to check)
 * 					  roll->(The roll you want to check)
 * Output (Return): status as an enumeration
 *
 * **************************/
Check_status StudentRollIsTaken(FIFO_Buf_t* fifo,uint32_t roll){

	uint32_t i;
	sDataBlock* pTemp = fifo->Tail;

	for(i=0;i<fifo->Count;i++ , pTemp++){

		if(roll == pTemp->roll)
			return TRUE;
	}

	return FALSE;

}


