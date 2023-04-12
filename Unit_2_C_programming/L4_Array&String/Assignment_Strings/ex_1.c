/*
 ============================================================================
 Name        : ex_1.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
This program asks user to enter a string and a character and this program checks
how many times that character is repeated in the string entered by user.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define strlen 150
int main(void) {

	char text[strlen],character;
	int count=0,i;

	printf("Enter a string: ");
	fflush(stdout); fflush(stdin);
	gets(text);

	printf("\nEnter a character to find frequency: ");
	fflush(stdout); fflush(stdin);
	scanf("%c",&character);

	for(i=0;i<strlen;i++)
	{
		if(text[i] == character)
		{
			count++;
		}

	}

	printf("\nFrequency of %c = %d",character,count);

	return EXIT_SUCCESS;
}
