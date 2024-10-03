#include <stdio.h>

int main ()

{
	int a, b;
	
	printf("Enter the first number : ");
	scanf("%d", &a);
	
	printf("Enter the second number : ");
	scanf("%d", &b);
	
	if ( a == b ) {
		printf("\nBoth numbers are equal");
	} else {
		printf("\nNumbers are not equal");
	}
	
	return 0;
}
