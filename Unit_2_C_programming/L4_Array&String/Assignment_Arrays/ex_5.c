/*
 ============================================================================
 Name        : ex_5.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
C Program to Search an element in Array
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int num,i,element;

	printf("Enter no of elements: ");
	fflush(stdout);
	scanf("%d",&num);

	int a[num];
	for(i=0;i<num;i++)
	{
		scanf("%d",&a[i]);
	}

	printf("\nEnter the elements to be searched: ");
	fflush(stdout);
	scanf("%d",&element);
	for(i=0;i<num;i++)
	{
		if(a[i] == element)
		{
			printf("\nNumber found at the location = %d",i+1);
			break;
		}
		else if(i == num-1){
			printf("\nNumber not found!");
		}
	}

	return EXIT_SUCCESS;
}
