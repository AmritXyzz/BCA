#include <stdio.h>

int main ()
{
	float celsius, value;
	printf("Enter the celsius value : ");
	scanf("%f", &celsius);
	
	value = celsius*1.8+32; 
	printf("The value in Fahrenheit is : %.2f", value);
	
	return 0;
}
