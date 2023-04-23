/*
 ============================================================================
 Name        : ex_1.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
Prime Numbers Between two Intervals by Making User-defined
Function
 ============================================================================
 */

#include <stdio.h>

int prime_check(int x);

int main(void)
{
	int start,end,i;

	printf("Enter two numbers (intervals): ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&start,&end);

	printf("\nPrime numbers between %d and %d are: ",start,end);

	for(i=start; i <= end ;i++)
	{
		if(prime_check(i))
			printf("%d ",i);

	}

	return 0;
}

int prime_check(int x)
{
	int i;

	if(x == 0 ||x == 1 )
		return 0;

	for(i=2; i < x ;i++)
	{
		if(x%i == 0)
			return 0;
	}
	return 1;
}

