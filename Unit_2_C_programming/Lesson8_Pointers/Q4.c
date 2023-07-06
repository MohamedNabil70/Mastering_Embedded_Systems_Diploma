//Q4
//Write a program in C to print the elements of an array in reverse order
//Code by : Mohamed Nabil

#include "stdio.h"
#include <stdlib.h>


int main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int array_length,arr[15],i,*p_arr=NULL;

	printf ("Enter the number of elements to store in the array (max 15) : ");
	scanf("%d",&array_length);


	printf ("\nEnter %d elements in the array :\n",array_length);
	for(i=0 ; i<array_length ;i++)
	{
		printf ("element - %d : ",i+1);
		scanf("%d",&arr[i]);
	}

	p_arr = &arr[array_length-1];
	printf ("\nThe elements of array in reverse order are : \n");
	for(i= array_length ; i>0 ;i--)
	{
		printf ("element - %d : %d\n",i,*p_arr);
		p_arr--;

	}

	return 0;
}
