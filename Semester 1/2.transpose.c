#include <stdio.h>	

int main(){
    int matrix[10][10], mat[10][10], row, column;
    printf("enter number of rows of matrix : ");
    scanf("%d",&row);
    printf("enter mumber of columns of matrix:");
    scanf("%d",&column);
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("a[%d][%d]: ", i, j);
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("matrix is : \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("%d ",matrix[i][j]);
        }printf("\n");
    }
    for(int i=0; i<column; i++){
        for(int j=0; j<row; j++){
           mat[i][j]=matrix[j][i];
        }
    }
    printf("tranpose of matrix is : \n");
    for(int i=0; i<column; i++){
        for(int j=0; j<row; j++){
            printf("%d ",mat[i][j]);
        }printf("\n");
    }
    return 0;
}