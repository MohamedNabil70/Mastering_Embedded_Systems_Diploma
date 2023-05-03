//: C Program to Add Two Complex Numbers by Passing Structure to a Function
//By:Mohamed Nabil Mohamed Mohamed

#include <stdio.h>

struct Scomplex{

	float Real;
	float imaginary;
};

struct Scomplex ComplexAdd(struct Scomplex num1,struct Scomplex num2);

int main()
{
	struct Scomplex num[2];
	struct Scomplex sum;

	printf("For 1st complex number Enter real and imaginary respectively: \n");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&num[0].Real,&num[0].imaginary);

	printf("For 2nd complex number Enter real and imaginary respectively: \n");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&num[1].Real,&num[1].imaginary);

	sum= ComplexAdd(num[0],num[1]);

	printf("\nSum=%.1f+%.1fi",sum.Real,sum.imaginary);



	return 0;
}
struct Scomplex ComplexAdd(struct Scomplex num1,struct Scomplex num2)
{
	struct Scomplex sum;
	sum.Real=num1.Real+num2.Real;
	sum.imaginary=num1.imaginary+num2.imaginary;

	return sum;
}
