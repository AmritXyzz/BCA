#include <stdio.h>	

int main() {
    int n;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    int mat1[n][n], mat2[n][n], add[n][n], mult[n][n];
    // Input first matrix
    printf("Enter the elements of the first matrix\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
    // Input second matrix
    printf("Enter the elements of the second matrix\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }
    // Addition of matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            add[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    // Displaying the addition result
    printf("Addition of Matrix 1 and Matrix 2:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", add[i][j]);
        }
        printf("\n");
    }
    // Multiplication of matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mult[i][j] = 0;
            for (int k = 0; k < n; k++) {
                mult[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Displaying the multiplication result
    printf("Multiplication of Matrix 1 and Matrix 2:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mult[i][j]);
        }
        printf("\n");
    }
    return 0;
}