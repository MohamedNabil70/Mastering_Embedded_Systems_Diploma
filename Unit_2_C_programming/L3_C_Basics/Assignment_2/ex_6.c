/*
 ============================================================================
 Name        : ex_6.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

This program takes a positive integer from user(suppose user entered n ) then,
this program displays the value of 1+2+3+....n.r.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int n,i,sum=0;

	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&n);

for(i=1;i<=n;i++)
{
	sum += i;
}

printf("Sum = %d",sum);
		return EXIT_SUCCESS;
	}
