/*
 ============================================================================
 Name        : ex_1.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int x;

	printf("Enter an integer you want to check: ");
	fflush(stdout);
	scanf("%d",&x);


	if(x%2 == 0)
	{
		printf("\n%d is Even ",x);

	}else{
		printf("\n%d is Odd ",x);

	}
	return EXIT_SUCCESS;
}
