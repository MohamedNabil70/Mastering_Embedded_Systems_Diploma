/*
 ============================================================================
 Name        : ex_3.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
EX3:

Write C Program to Add Two Integers

i should see the Console as following:
##########Console-output###
Enter two integers: 12
11
Sum: 23
###########################
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int x,y,sum;

	printf("Enter two integers: ");
	fflush(stdout);
	scanf("%d %d",&x,&y);
	sum= x+y;
	printf("\nSum: %d",sum);

	return EXIT_SUCCESS;
}
