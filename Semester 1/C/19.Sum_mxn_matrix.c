#include <stdio.h>

int main() {
    int m, n;
    
    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);
    
    int matrix[m][n];
    
    printf("Enter the elements of the matrix:\n");
    
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int diagonalSum = 0;
    int minDimension = (m < n) ? m : n;
    
    for (i = 0; i < minDimension; i++) {
        diagonalSum += matrix[i][i];
    }
    
    printf("The sum of the diagonal elements is: %d\n", diagonalSum);
    
    return 0;
}
