//c function to sum numbers from 1 to 100 (without loop)
//By Mohamed Nabil Mohamed Mohamed
#include <stdio.h>

//This function finds sum numbers from 1 to x(without loop)
int SumOf(int x)
{
	int sum=0;

	Back_point:

	sum+=x;

	if(--x > 0)
		goto Back_point;

	return sum;
}


int main()
{
	printf("Sum of numbers from 1 to 100 = %d", SumOf(100));


	return 0;
}
