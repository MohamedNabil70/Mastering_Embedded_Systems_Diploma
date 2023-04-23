/*
 ============================================================================
 Name        : ex_4.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
C Program to Insert an element in an Array
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int a[40],n,i,element,location;

	printf("Enter no of elements: ");
	fflush(stdout);
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	printf("\nEnter the element to be inserted: ");
	fflush(stdout);
	scanf("%d",&element);

	printf("\nEnter the location: ");
	fflush(stdout);
	scanf("%d",&location);


	for(i=n;i>=location;i--)
	{
		a[i]=a[i-1];
	}

	n++;
	a[location-1] = element;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return EXIT_SUCCESS;
}
