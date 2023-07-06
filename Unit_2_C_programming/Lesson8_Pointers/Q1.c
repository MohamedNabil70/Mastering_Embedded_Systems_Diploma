//Q1
//Write a program in C to demonstrate how to handle the
//pointers in the program.
//Code by : Mohamed Nabil

#include "stdio.h"
#include <stdlib.h>


int main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int m= 29,* ab= NULL;


	printf ("Address of m : 0x%p \n",&m);
	printf ("Value of m : %d \n",m);

	ab=&m;
	printf ("\nNow ab is assigned with the address of m.\n");
	printf ("Address of pointer ab : 0x%p\n",ab);
	printf ("Content of pointer ab : %d\n",*ab);

	m=34;
	printf ("\nThe value of m assigned to 34 now.\n");
	printf ("Address of pointer ab : 0x%p\n",ab);
	printf ("Content of pointer ab : %d\n",*ab);

	*ab=7;
	printf ("\nThe pointer variable ab is assigned with the value 7 now.\n");
	printf ("Address of m : 0x%p \n",&m);
	printf ("Value of m : %d \n",m);
	return 0;
}
