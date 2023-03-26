/*
 ============================================================================
 Name        : ex_2.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
EX2:

Write C Program to Print a Integer Entered by a User
i should see the Console as following:
##########Console-output###
Enter a integer: 25
You entered: 25
###########################
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int X;

	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&X);
	printf("\nYou entered: %d",X);

	return EXIT_SUCCESS;
}
