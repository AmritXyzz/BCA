#include <stdio.h>

int main() {
    int i, num, evenSum = 0, oddSum = 0;

    printf("Enter a positive integer (N): ");
    scanf("%d", &num);

    if (num < 1) {
        printf("Please enter a positive integer greater than 0.\n");
    }
    
    for (i = 1; i <= num; i++) {
        if (i % 2 == 0) {
            evenSum += i;
        } else {
            oddSum += i;
        }
    }

    printf("Sum of even numbers from 1 to %d is: %d\n", num, evenSum);
    printf("Sum of odd numbers from 1 to %d is: %d\n", num, oddSum);

    return 0;
}
