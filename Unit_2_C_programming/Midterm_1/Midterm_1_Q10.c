//c function to count the max number of ones between two zeros
//By :Mohamed Nabil Mohamed Mohamed
#include <stdio.h>
#include <string.h>

int max_ones(short int x)
{
	int maxOnes=0,i,j,onesCount=0;

	for(i=15;i>=0;i--)
	{

		if(((x>>i) & 1) == 0 )
		{
			for(j=i-1;j>=0;j--)
			{
				if(((x>>j) & 1) == 1)
				{
					onesCount++;
				}else{
					if(maxOnes<onesCount)
						maxOnes=onesCount;
					onesCount=0;
					break;
				}
			}

		}else continue;


	}


	return maxOnes;
}

void print_bin(short int x)
{
	int i;
	printf("0");
	for(i=15;i>=0;i--)
	{
		if((x>>i) != 0)
			printf("%d",((x>>i) & 1));
	}

}


int main()
{

	short int num;

	printf("Enter a number to count the max number of ones between two zeros in its binary: ");
	fflush(stdin); fflush(stdout);
	scanf("%hu",&num);

	printf("\nBinary of %d is ",num);
	print_bin(num);
	printf("\nThe max number of ones between two zeros= %d",max_ones(num));


	return 0;
}
