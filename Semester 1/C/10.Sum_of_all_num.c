#include <stdio.h>

int main() {
    int i, n, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter a positive integer.\n");
    }

    for (i = 1; i <= n; i++) {
        sum += i;
    }

    printf("The sum of all numbers from 1 to %d is: %d\n", n, sum);

    return 0;
}
