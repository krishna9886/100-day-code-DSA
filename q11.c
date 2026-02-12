//Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).
#include <stdio.h>

int main() {
    int m,n;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);
    if (m != n) {
        printf("The matrix is not symmetric because it is not a square matrix.\n");
        return 0;
    }
    int A[m][n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    int isSymmetric = 1; 
    for(int m=0;m<n;m++){
        for(int n=0;n<n;n++){
            if(A[m][n] != A[n][m]){
                isSymmetric = 0; 
                break;
            }
        }
        if(isSymmetric==0)
        {
            printf("The matrix is not symmetric.\n");
            break;
        }
    }
    if(isSymmetric==1){
        printf("The matrix is symmetric.\n");
    } 
    
    return 0;
}