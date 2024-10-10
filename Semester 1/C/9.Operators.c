#include <stdio.h>

int main ()
{
	float n1, n2;
	char operator;
	
	printf("Enter an expression : ");
	scanf("%f %c %f", &n1, &operator, &n2);
	
	printf("\rResult : ");
	
	switch (operator) {
		case '+':
			printf("%.2f", n1 + n2);
			break;
		
		case '-':
			printf("%.2f", n1 - n2);
			break;
			
		case '*':
		case 'x':
			printf("%.2f", n1 * n2);
			break;
			
		case '/':
			if ( n2 != 0 ) {
			    printf("%.2f", n1 / n2);
			} else {
				printf("Error : Division by zero is not allowed.");
			};
			break;
			
		default:
			printf("Error");
			break;
		}
	return 0;
}
