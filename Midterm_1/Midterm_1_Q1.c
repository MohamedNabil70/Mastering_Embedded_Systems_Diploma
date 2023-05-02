
//By :Mohamed Nabil Mohamed Mohamed
#include <stdio.h>

int sumDigits(int x)
{
	int sum =0;
	for(;x>0;x=x/10)
	{
			sum+= x%10;
	}
	return sum;
}
int main()
{
	int num;

	printf("Enter a positive integer to find the sum of its digits: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	printf("\nThe sum of digits of %d = %d",num,sumDigits(num));



	return 0;
}
