//c function to print all prime numbers between two numbers
//By :Mohamed Nabil Mohamed Mohamed
#include <stdio.h>

int PrimeCheck(int num )
{
	//if flag = 1 the number is prime
	int flag=1 ,i;
	if(num == 0)
		 flag=0;

	if(num == 1)
		flag=1;

	for(i=2;i<num;i++)
	{
		if(num%i != 0)
		{
			continue;
		}
		flag =0;
	}
	return flag;
}
int main()
{
	int num1 , num2 , i;

	printf("Enter 2 numbers to find the prime numbers between them: ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&num1,&num2);


	printf("\nThe prime numbers between %d & %d are: ",num1,num2);

	for(i=num1;i<=num2;i++)
	{
		if(PrimeCheck(i))
			printf("%d ",i);
	}



	return 0;
}
