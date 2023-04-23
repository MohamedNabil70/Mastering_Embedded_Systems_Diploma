/*
 ============================================================================
 Name        : ex_1.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
C program to find sum of two matrix of order 2*2 using multidimensional
arrays where, elements of matrix are entered by user.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

float a[2][2],b[2][2],sum[2][2];
int i,j;
//matrix a insertion
printf("Enter the elements of 1st matrix\n");
for(i=0;i<2;i++)
{
	for(j=0;j<2;j++)
	{
		printf("Enter a%d%d: ",i+1,j+1);
		fflush(stdout);
		scanf("%f",&a[i][j]);

	}
}
//matrix b insertion
printf("Enter the elements of 2nd matrix\n");
for(i=0;i<2;i++)
{
	for(j=0;j<2;j++)
	{
		printf("Enter b%d%d: ",i+1,j+1);
		fflush(stdout);
		scanf("%f",&b[i][j]);

	}
}
//matrix sum calculation
for(i=0;i<2;i++)
{
	for(j=0;j<2;j++)
	{
sum[i][j]= a[i][j]+b[i][j];

	}
}
//matrix sum display
printf("\nSum Of Matrix:\n");

for(i=0;i<2;i++)
{
	for(j=0;j<2;j++)
	{
		printf("%.1f	",sum[i][j]);


	}
	printf("\n");
}

	return EXIT_SUCCESS;
}
