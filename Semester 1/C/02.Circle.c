#include <stdio.h>
#define PI 3.14

int main()
{
    float area, circum, radius;
    printf("Enter the radius of a circle (in cm) : ");
    scanf("%f",&radius);
    
    area = 2*PI*radius;
    printf("The area of a circle is : %.2f\n", area);
    
    circum = PI*radius*radius;
    printf("The circumference of a circle is : %.2f", circum);
	
    return 0;
}
