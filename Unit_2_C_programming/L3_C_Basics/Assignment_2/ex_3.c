/*
 ============================================================================
 Name        : ex_3.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

In this program user is asked to enter three numbers and this program will
 find the largest number among three numbers entered by user.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float x,y,z;

	printf("Enter three numbers: ");
	fflush(stdout);
	scanf("%f %f %f",&x,&y,&z);

	if(x>y)
	{
		if(x>z)
			printf("\nLargest number = %.2f ",x);
		else
			printf("\nLargest number = %.2f ",z);

	}else
	{
		if(y>z)
			printf("\nLargest number = %.2f ",y);
		else
			printf("\nLargest number = %.2f ",z);
	}
		return EXIT_SUCCESS;
	}
