//c function to return unique number in array
//By :Mohamed Nabil Mohamed Mohamed
#include <stdio.h>

int uniqueNum(int a[],int length)
{
	int unique=0,i,j,repFlag;
	for(i=0;i<length;i++)
	{

		repFlag=0;
		for(j=length;j>=0;j--)
		{
			if(a[i] == a[j])
			{
							repFlag ++;
			}
		}
if(repFlag == 1)
	unique=a[i];

	}

	return unique;
}
int main()
{
	int a[7]={4,2,5,2,5,7,4};


printf("%d",uniqueNum(a,7));



	return 0;
}
