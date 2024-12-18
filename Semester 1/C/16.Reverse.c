#include <stdio.h>

int main() {
    int number, reverse = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    int original = number;

    number = (number < 0) ? -number : number;
    while (number > 0) {
        reverse = reverse * 10 + number % 10;
        number = number/10;
    }

    if (original < 0) {
        reverse = -reverse;
    }
    
    printf("Reverse of the number: %d\n", reverse);

    return 0;
}
