//C Program to Add Two Distances (in inch-feet) System Using Structures
//By:Mohamed Nabil Mohamed Mohamed

#include <stdio.h>

struct Sdistance{

	int feet;
	float inches;
};


int main()
{
	struct Sdistance distance[2];
	struct Sdistance SumDistance;
	printf("Enter information for 1st distance: \n");

	printf("Enter feet: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&distance[0].feet);

	printf("Enter inch: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&distance[0].inches);

	printf("\nEnter information for 2nd distance: \n");

	printf("Enter feet: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&distance[1].feet);

	printf("Enter inch: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&distance[1].inches);


	//sum feet and inches on their own
	SumDistance.feet = distance[0].feet + distance[1].feet;
	SumDistance.inches = distance[0].inches + distance[1].inches;
	if(SumDistance.inches > 12)
	{
		SumDistance.inches-=12;
		SumDistance.feet++;
	}else;

	printf("\nSum of distances = %d'-%.1f\" ",SumDistance.feet,SumDistance.inches);



	return 0;
}
