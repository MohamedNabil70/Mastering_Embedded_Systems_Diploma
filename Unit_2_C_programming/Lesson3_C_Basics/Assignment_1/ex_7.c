/*
 ============================================================================
 Name        : ex_7.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
EX7:
it is an interview trick

Write Source Code to Swap Two Numbers without temp variable.
#############################
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float a,b;

	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f",&a);

	printf("\nEnter value of b: ");
	fflush(stdout);
	scanf("%f",&b);

	a=a*b;
	b=a/b;
	a=a/b;

	printf("\nAfter swapping, value of a = %.2f",a);
	printf("\nAfter swapping, value of b = %.2f",b);

	return EXIT_SUCCESS;
}
