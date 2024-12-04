#include <stdio.h>

int main() {
    int i ,n, first = 0, second = 1, next;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
    }

    printf("Fibonacci Series: ");

    for (i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%d", first);
        } else if (i == 2) {
            printf(", %d", second);
        } else {
            next = first + second;
            printf(", %d", next);
            first = second;
            second = next;
        }
    }
    printf("\n");

    return 0;
}
