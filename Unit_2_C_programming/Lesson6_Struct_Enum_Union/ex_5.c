//:C Program to find area of a circle, passing arguments to macros. [Area of circle=πr^2]
//By:Mohamed Nabil Mohamed Mohamed

#include <stdio.h>

#define AREA(R) 3.14*R*R

int main()
{
	int radius;

	printf("Enter the radius: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&radius);


			printf("Area=%.2f\n",AREA(radius));

	return 0;
}
