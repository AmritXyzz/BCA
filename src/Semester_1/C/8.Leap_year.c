#include <stdio.h>

int main()
{
    int year, x;
    
    printf("Enter year : ");
    scanf("%d", &year);
    
    x = year % 4;
    
    if ( x == 0 ) {
    	printf("%d is leap year", year);
    } else {
	printf("%d is not a leap year", year);
    }
    return 0;
}
