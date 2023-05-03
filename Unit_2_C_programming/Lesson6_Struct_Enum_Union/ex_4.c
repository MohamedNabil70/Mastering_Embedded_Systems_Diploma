//: C Program to Store Information of Students Using Structure
//By:Mohamed Nabil Mohamed Mohamed
/*In this program, a structure (student) is created which contains name, roll and marks as its data member.
 * Then, an array of structure of 10 elements is created. Then, data (name, roll and marks)
 * for 10 elements is asked to user and stored in array of structure. Finally, the data entered by user is 
displayed.*/
#include <stdio.h>
#define STNUM 10


struct SstudentData{
	char name[50];
	int roll;
	int marks;
}student[STNUM];

int main()
{
	int i;

	printf("Enter information of students: \n");

	for(i=0;i<STNUM;i++)
	{
		printf("\nFor roll number %d\n",i+1);
		printf("Enter name: ");
			fflush(stdin); fflush(stdout);
			fgets(student[i].name,50,stdin);


			printf("Enter marks: ");
			fflush(stdin); fflush(stdout);
			scanf("%d",&student[i].marks);
	}



	printf("\nDisplaying information of students:\n");

	for(i=0;i<STNUM;i++)
	{
		printf("\nInformation for roll number %d: ",i+1);
		printf("\nName: %s",student[i].name);
		printf("Marks: %d\n",student[i].marks);

	}




	return 0;
}
