/*
 ============================================================================
 Name        : ex_2.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
C Program to Calculate Average Using Arrays
This program takes n number of element from user(where, n is specified by user),
stores data in an array and calculates the average of those numbers.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int n,i;
	printf("Enter the number of data: ");
	fflush(stdout);
	scanf("%d",&n);

	float a [n],sum=0,average;

	for(i=0;i<n;i++)
	{
		printf("%d.Enter number: ",i+1);
		fflush(stdout);
		scanf("%f",&a[i]);
	}


	for(i=0;i<n;i++)
	{
		sum+=a[i];
	}

	average = sum/n;
	printf("\nAverage = %.2f",average);
			return EXIT_SUCCESS;
}
