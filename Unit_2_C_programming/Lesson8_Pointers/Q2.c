//Q2
//Write a program in C to print all the alphabets using a pointer.
//Go to the editor
//Code by : Mohamed Nabil

#include "stdio.h"
#include <stdlib.h>


int main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char alphabet[26],*ptr=NULL;
	int i;
	for(i=0;i<26;i++)
	{
		alphabet[i]='A'+i;
	}

	ptr=alphabet;

	for(i=0;i<26;i++)
	{
		printf ("%c ",ptr[i]);
	}



	return 0;
}
