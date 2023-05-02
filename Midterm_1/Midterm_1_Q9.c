//c function to reverse words in string
//By :Mohamed Nabil Mohamed Mohamed
#include <stdio.h>
#include <string.h>

void words_reverse(char text[])
{
	int i,j,length;
	length = strlen(text);

	for(i=length;i>=0;i--)
	{
		if(text[i]==' ')
		{
			for(j=i+1;text[j]!= 0 && text[j]!= ' ' ;j++)
			{
				printf("%c",text[j]);
			}
			printf(" ");
		}

		if(i== 0)
		{
			for(j=i;text[j]!= 0 && text[j]!= ' ' ;j++)
			{
				printf("%c",text[j]);
			}
			printf(" ");
		}
	}

}

int main()
{

	char text[150];
	printf("Enter a sentence to reverse: ");
	fflush(stdin); fflush(stdout);
	gets(text);

	printf("\nReverse is: ");
	words_reverse(text);




	return 0;
}
