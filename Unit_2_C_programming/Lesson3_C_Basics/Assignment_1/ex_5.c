/*
 ============================================================================
 Name        : ex_5.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
EX5:

Write C Program to Find ASCII Value of a Character

#########Console_output######
Enter a character: G
ASCII value of G = 71
#############################
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char x;

	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&x);

	printf("\nASCII value of %c = %d",x,x);

	return EXIT_SUCCESS;
}
