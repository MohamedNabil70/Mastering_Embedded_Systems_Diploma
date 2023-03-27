/*
 ============================================================================
 Name        : ex_4.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

This program takes a number from user and checks
whether that it is + or - or 0

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float x;

	printf("Enter a number: ");
	fflush(stdout);
	scanf("%f",&x);

	if(x>0)
	{
		printf("%.2f is positive ",x);

	}else if(x==0){

		printf("You entered zero ");
	}else
	{
		printf("%.2f is negative ",x);
	}
		return EXIT_SUCCESS;
	}
