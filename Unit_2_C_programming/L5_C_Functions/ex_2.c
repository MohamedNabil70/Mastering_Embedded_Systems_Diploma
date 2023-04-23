/*
 ============================================================================
 Name        : ex_2.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
C program to Calculate Factorial of a Number Using Recursion
 ============================================================================
 */

#include <stdio.h>

int factorial(int n);

int main(void)
{
	int n;

	printf("Enter an positive integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);


	printf("\nFactorial of %d = %d",n,factorial(n));
	return 0;
}

int factorial(int n)
{
	if(n>=0)
	{
		if(n>0)
			return n*factorial(n-1);
		else
			return 1;
	}
	else
	{
		printf("Error!!");
	return 0;
	}

}

