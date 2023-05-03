//C Program to Store Information(name, roll and marks) of a Student Using Structure
//By:Mohamed Nabil Mohamed Mohamed

/*In this program, a structure (student) is created which contains name, roll and marks as its data member.
 *  Then, a structure variable(s) is created. Then, data (name, roll and marks) is taken from user
 *  and stored in data members of structure variables. Finally, the data entered by user is displayed.*/
#include <stdio.h>

struct SstudentData{
	char name[50];
	int roll;
	int marks;
}student;

int main()
{

	printf("Enter information of students: \n");

	printf("\nEnter name: ");
	fflush(stdin); fflush(stdout);
	fgets(student.name,50,stdin);

	printf("Enter roll number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&student.roll);

	printf("Enter marks: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&student.marks);

	printf("\nDisplaying Information");
	printf("\nname: %s",student.name);
	printf("Roll: %d",student.roll);
	printf("\nMarks: %d",student.marks);


	return 0;
}
