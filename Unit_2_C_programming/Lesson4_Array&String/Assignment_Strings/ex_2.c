/*
 ============================================================================
 Name        : ex_2.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
You can use standard library function strlen() to find the length of a string
but, this program computes the length of a string manually without using strlen() funtion.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define strlen 150
int main(void) {

	char text[strlen];
	int length=0,i;

	printf("Enter a string: ");
	fflush(stdout); fflush(stdin);
	gets(text);


	for(i=0;text[i] != 0;i++)
	{
		length++;
	}

	printf("\nLength of string: %d",length);

	return EXIT_SUCCESS;
}
