//Q3
//Write a program in C to print a string in reverse using a pointer
//Code by : Mohamed Nabil

#include "stdio.h"
#include <stdlib.h>


int main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char string [50],*Sptr=NULL;
	int i,count=0;
	printf ("Input a string : ");
	gets(string);

	for(i=0;string[i] != '\0' ;i++)
	{
		count++;
	}

	Sptr = string;

	printf ("\n");
	for( ;count>=0;count--)
	{
		printf("%c",*(Sptr+count));
	}

	return 0;
}
