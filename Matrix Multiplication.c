#include <stdio.h>


/*
 * 
 * (Matrix Multiplication) Let A be an M x P matrix array, and let B be a P x N matrix array.
 * This algorithm sotres the product of A and B in an M x N matrix array C
 * 
 * 
 * 1. Repeat Steps 2 to 4 for I = 1 to M;
 * 2.     Repeat Steps 3 and 4 for J = 1 to N;
 * 3.         Set C[I, J] := 0 [Initializes C[I, J]];
 * 4.     Repeat for K = 1 to P:
 *            C[I, J] := C[I, J] + A[I, K] * B[K, J]
 * 5. Exit.
 * 
 * 
 * */



int main() {
    
    int rowA, colA;
    printf("Enter number of rows for Matrix A: ");
    scanf("%d", &rowA);
    printf("Enter number of columns for Matrix A: ");
    scanf("%d", &colA);
    
    int rowB, colB;
    printf("Enter number of rows for Matrix B: ");
    scanf("%d", &rowB);
    printf("Enter number of columns for Matrix B: ");
    scanf("%d", &colB);
    
    if(colA != rowB) {
        printf("Cannot multiply\n");
        return 1;
    }
    
    int matrixA[rowA][colA], matrixB[rowB][colB], matrixC[rowA][colB];
    
    printf("\nEnter elements for Matrix A (%d x %d):\n", rowA, colA);
    for(int i = 0; i < rowA; i++) {
        for(int j = 0; j < colA; j++) {
            printf("Enter A[%d][%d]: ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }
    
    printf("\nEnter elements for Matrix B (%d x %d):\n", rowB, colB);
    for(int i = 0; i < rowB; i++) {
        for(int j = 0; j < colB; j++) {
            printf("Enter B[%d][%d]: ", i, j);
            scanf("%d", &matrixB[i][j]);
        }
    }
    
    for(int i = 0; i < rowA; i++) {
        for(int j = 0; j < colB; j++) {
            matrixC[i][j] = 0;
        }
    }
    
    for(int i = 0; i < rowA; i++) {
        for(int j = 0; j < colB; j++) {
            for(int k = 0; k < colA; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    
    printf("\nResultant Matrix (A x B) (%d x %d): \n", rowA, colB);
    for(int i = 0; i < rowA; i++) {
        for(int j = 0; j < colB; j++) {
            printf("%d\t", matrixC[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;    // Exit
}
