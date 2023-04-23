/*
 ============================================================================
 Name        : ex_3.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
C program to Reverse a Sentence Using Recursion
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

void text_reverse(void);
int main(void)
{

	printf("Enter a sentence: ");
	fflush(stdin); fflush(stdout);
	printf("\n");
	text_reverse();

	return 0;
}

void text_reverse(void) {
	char c;
	scanf("%c", &c);

	if(c!='\n')
	{
		text_reverse();
		printf("%c",c);
	}
}
