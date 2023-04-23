/*
 ============================================================================
 Name        : ex_4.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
C program to Calculate the Power of a Number Using Recursion
 ============================================================================
 */

#include <stdio.h>

int Power(int,int);
int main(void)
{
int base,PowerNum;

	printf("Enter base number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&base);

	printf("\nEnter power number (positive integer): ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&PowerNum);

	printf("\n%d ^ %d = %d",base,PowerNum,Power(base,PowerNum));
	return 0;
}


int Power(int x , int y)
{
	if(y>0)
		return x * Power(x,y-1);
	else
		return 1;

}
