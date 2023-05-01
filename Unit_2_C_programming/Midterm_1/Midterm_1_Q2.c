//c function to take an integer number and calculate it's square root
//By :Mohamed Nabil Mohamed Mohamed
#include <stdio.h>

float square_root(int x)
{
	float Sqrt,i ;

	 for(i=1; i<x ;i+=0.00001)
	 {
		 //casting to make it possible for i^2 to be equal to x
		 if((int)(i*i) == x)
		 {
			 Sqrt = i;
			 break;
		 }else
			 continue;

	 }
	return Sqrt;
}
int main()
{
	int num;

	printf("Enter a positive integer to find it's square root: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	printf("\nThe square root of %d = %.3f",num,square_root(num));



	return 0;
}
