/*
 ============================================================================
 Name        : ex_4.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
EX4:

Write C Program to Multiply two Floating Point Numbers
i should see the Console as following:
##########Console-output###

###########################
Enter two numbers: 2.4
1.1
Product: 2.640000
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float x,y,Product;

	printf("Enter two numbers: ");
	fflush(stdout);
	scanf("%f %f",&x,&y);
	Product= x*y;
	printf("\nProduct: %f",Product);

	return EXIT_SUCCESS;
}
