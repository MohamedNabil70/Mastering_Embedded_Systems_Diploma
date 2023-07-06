//Q5
//Write a program in C to show a pointer to an array which contents
//are pointer to structure.
//Code by : Mohamed Nabil

#include "stdio.h"
#include <stdlib.h>

struct Employee {
char name[50];
int id;
};

int main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	struct Employee Employee1={"Mohamed",1000},Employee2= {"Nabil",1001},Employee3= {"Alex",1002};
	struct Employee (*pEmployee[3]) = {&Employee1,&Employee2,&Employee3};
	struct Employee (*(*ps)[3])=&pEmployee;      //ps is a pointer to an array of 3 elements which contents are pointers to structure



	printf ("\nEmployee Name : %s\n",(**(*ps+2)).name);
	printf ("Employee ID : %d\n",(**(*ps+2)).id);



	return 0;
}
