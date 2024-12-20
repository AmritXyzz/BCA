#include <stdio.h>

#define MAX 10 // Maximum size of the matrix

void addMatrices(int n, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    int i, j; // Declare loop variables outside
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void multiplyMatrices(int n, int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX]) {
    int i, j, k; // Declare loop variables outside
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            result[i][j] = 0;
            for (k = 0; k < n; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
}

void printMatrix(int n, int matrix[MAX][MAX]) {
    int i, j; // Declare loop variables outside
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int i, j, n;
    int a[MAX][MAX], b[MAX][MAX], sum[MAX][MAX], product[MAX][MAX];

    printf("Enter the order of the matrices (n): ");
    scanf("%d", &n);

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &b[i][j]);

    addMatrices(n, a, b, sum);
    multiplyMatrices(n, a, b, product);

    printf("Sum of matrices:\n");
    printMatrix(n, sum);

    printf("Product of matrices:\n");
    printMatrix(n, product);

    return 0;
}
