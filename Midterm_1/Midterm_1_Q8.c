//c function to take an array and reverse its elements
//By :Mohamed Nabil Mohamed Mohamed
#include <stdio.h>

void arr_reverse(int arr[],int length)
{
	int i ,t[length];
	for(i=0;i<length;i++)
	{
		t[i]=arr[length-i-1];
	}

	for(i=0;i<length;i++)
	{
		arr[i]=t[i];
	}
}

int main()
{

	int i,a[5]={1,2,3,4,5},length;

	length = sizeof(a)/sizeof(a[0]);
printf("Array : ");
	for(i=0;i<length;i++)
	{
		printf("%d ",a[i]);
	}

	arr_reverse(a,length);

	printf("\n\nReversed array : ");
		for(i=0;i<length;i++)
		{
			printf("%d ",a[i]);
		}

	return 0;
}
