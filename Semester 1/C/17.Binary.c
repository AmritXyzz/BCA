#include <stdio.h>

int main() {
    int choice, number;

    printf("Choose conversion:\n1. Binary to Decimal\n2. Decimal to Binary\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Binary to Decimal
        printf("Enter a binary number: ");
        scanf("%d", &number);
        int decimal = 0, base = 1;

        while (number > 0) {
            decimal += (number % 10) * base;
            number /= 10;
            base *= 2;
        }

        printf("Decimal: %d\n", decimal);
        
    } else if (choice == 2) {
        // Decimal to Binary
        printf("Enter a decimal number: ");
        scanf("%d", &number);

        if (number == 0) {
            printf("Binary: 0\n");
        } else {
            int binary[32], i = 0;
            while (number > 0) {
                binary[i++] = number % 2;
                number /= 2;
            }

            printf("Binary: ");
            
            int j;
            for (j = i - 1; j >= 0; j--) {
                printf("%d", binary[j]);
            }
            printf("\n");
        }
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
