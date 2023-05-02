//c function to count number of ones in binary number
//By :Mohamed Nabil Mohamed Mohamed
#include <stdio.h>

int OnesCount(short int number)
{
int i,sum=0;
	for(i=0 ;i<=16;i++)
	{
		if(((number>>i) & 1) == 1 )
			sum++;
	}
return sum;
}

void print_bin(short int number)
{
	int i;

	for(i=15;i>=0;i--)
	{
		if((number>>i) != 0)
			printf("%d",((number>>i) & 1));
	}

}
int main()
{
	short int num;

	printf("Enter a number to count number of ones in its binary: ");
	fflush(stdin); fflush(stdout);
	scanf("%hu",&num);

	printf("\nBinary of %d is ",num);
	print_bin(num);
	printf("\nNumber of ones= %d",OnesCount(num));


	return 0;
}
