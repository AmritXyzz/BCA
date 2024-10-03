#include <stdio.h>

int main ()
{
	float P, R, T, SI;
	printf("Enter the principal amount : ");
	scanf("%f",&P);
	
	printf("Enter the rate of interest (in %%) : ");
	scanf("%f",&R);
	
	printf("Enter the time period (in years) : ");
	scanf("%f",&T);
	
	SI = (P*R*T)/100;
	printf("\n\nThe simple interest is : %.f\n", SI);
	
	return 0;
}
