/*
 ============================================================================
 Name        : ex_3.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
This program asks user to enter a matrix (size of matrix is specified by user)
and this program finds the transpose of that matrix and displays it.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {


	int i,j,rows,columns;

	printf("Enter rows and column of matrix: \n");
	fflush(stdout);
	scanf("%d %d",&rows,&columns);


	int a [rows][columns],transpose [columns][rows];

	printf("\nEnter elements of matrix:\n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			printf("Enter element a%d%d: ",i+1,j+1);
			fflush(stdout);
			scanf("%d",&a[i][j]);

		}
	}
	//matrix display
	printf("\nEntered matrix:\n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			printf("%d	",a[i][j]);
		}
		printf("\n");
	}

	//matrix transpose calculation
	for(i=0;i<columns;i++)
	{
		for(j=0;j<rows;j++)
		{
			transpose[i][j] = a[j][i] ;
		}

	}

	//matrix transpose display
	printf("\nTranspose of Matrix:\n");
	for(i=0;i<columns;i++)
	{
		for(j=0;j<rows;j++)
		{
			printf("%d	",transpose[i][j]);
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
