#include <stdio.h>

int main ()
{
	int a, b, x;
	printf("Value of 'a' is : ");
	scanf("%d", &a);
	
	printf("Value of 'b' is : ");
	scanf("%d", &b);
	
	x = a;
	a = b;
	b = x;
	
	printf("\nAfter swapping :-\n");
	
	printf("a = %d", a);
	printf("\nb = %d", b);
	
	return 0;
	
}
