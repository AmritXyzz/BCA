#include <stdio.h>

int main()
{
    int a, b, c, largest;
    printf("Enter first number : ");
    scanf("%d", &a);
    
    printf("Enter second number : ");
    scanf("%d", &b);
    
    printf("Enter third number : ");
    scanf("%d", &c);
    
    if ( a>b && b>c ) {
    largest = a;
    
    } else if ( b>c && c>a ) {
    largest = b;
    
    } else {
    largest = c;
    };
    
    printf("The largest of these numbers is : %d" , largest);
    
    return 0;
}
