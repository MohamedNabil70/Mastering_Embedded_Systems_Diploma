/*
 ============================================================================
 Name        : ex_2.c
 Author      : Mohamed Nabil Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 This program asks user to enter a character and checks
 whether that character is vowel (a, e, i, o and u) or not.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char x;

	printf("Enter an alphabet: ");
	fflush(stdout);
	scanf("%c",&x);


	if(x==65 ||x==97 ||x== 69 ||x== 101 ||x==73 ||x==105||
			x==79 ||x==111 ||x==85 ||x== 117)
	{
		printf("\n %c is a vowel. ",x);

	}else{
		printf("\n %c is a consonant. ",x);
	}
	return EXIT_SUCCESS;
}
