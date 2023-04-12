/*
 ============================================================================
 Name        : ex_3.c
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
#include <string.h>

#define stringlen 150
int main(void) {

	char text[stringlen],reverse[stringlen];
	int length=0,i;

	printf("Enter the string: ");
	fflush(stdout); fflush(stdin);
	gets(text);

length = strlen(text);

for(i=0;text[i]!=0;i++)
{
	reverse[i] = text[length-i-1];
}
//important step to close string reverse
reverse[length] = 0;

	printf("Reverse string is : %s",reverse);

	return EXIT_SUCCESS;
}
