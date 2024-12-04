#include <stdio.h>

int factorial(int n) {
    int result = 1;
    int i;
    for (i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;

    printf("Enter a positive integer (0-12): ");
    scanf("%d", &n);

    if (n < 0 || n > 100) {
        printf("Please enter a non-negative integer between 0 and 12.\n");
    }

    printf("Factorial of %d is: %d\n", n, factorial(n));

    return 0;
}
