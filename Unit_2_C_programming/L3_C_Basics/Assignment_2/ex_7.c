/*
 ============================================================================
 Name        : ex_7.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

This program takes an integer from a user. If user enters negative integer,
this program will display error message and if user enters non-negative integer,
this program will display the factorial of that number.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int n,i,fact=1;

	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&n);

	if(n>0)
	{
		for(i=1;i<=n;i++)
		{
			fact *= i;
		}
		printf("%d Factorial = %d ",n,fact);

	}else if(n==0)
	{
		printf("0 Factorial = 1 ");
	}else{
		printf("Error!!! Factorial of negative number doesn't exist.");
	}





	return EXIT_SUCCESS;
}
