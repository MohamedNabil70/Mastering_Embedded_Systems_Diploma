//c function to reverse digits in number
//By :Mohamed Nabil Mohamed Mohamed
#include <stdio.h>

void Reverse(int num)
{
int i;
	for(i=num ;i>0;i/=10)
	{
		printf("%d",i%10);
	}

}
int main()
{
	int num;

	printf("Enter a number to reverse its digits: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);


	printf("\nReverse= ");

	Reverse(num);


	return 0;
}
