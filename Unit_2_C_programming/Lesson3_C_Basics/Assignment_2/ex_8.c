/*
 ============================================================================
 Name        : ex_8.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

This program takes an arithmetic operator (+, -, *, /) and two operands
from a user and performs the operation on those two operands depending upon
the operator entered by user.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float x,y,result=0;
	char operation;
	printf("Enter operator either + or - or * or / : \n");
	fflush(stdout);
	scanf("%c",&operation);

	printf("Enter two operands: ");
	fflush(stdout);
	scanf("%f %f",&x,&y);


	switch(operation)
	{
	case '+':
		result = x+y;
		printf("\n %.1f %c %.1f = %.1f",x,operation,y,result);

		break;
	case '-':
		result = x-y;
		printf("\n %.1f %c %.1f = %.1f",x,operation,y,result);

		break;
	case '*':
		result = x*y;
		printf("\n %.1f %c %.1f = %.1f",x,operation,y,result);

		break;
	case '/':

		result = x/y;
		printf("\n %.1f %c %.1f = %.1f",x,operation,y,result);
		break;


	}




	return EXIT_SUCCESS;
}
