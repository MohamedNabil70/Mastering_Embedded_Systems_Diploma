/*
 ============================================================================
 Name        : ex_5.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

This program takes a character from user and checks
whether that character is an alphabet or not.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char x;

	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&x);

	if((x>=65 && x<=90) || (x>=97 && x<=122))
	{
		printf("%c is an alphabet ",x);

	}else
		{
			printf("%c is not an alphabet ",x);
		}
		return EXIT_SUCCESS;
	}
