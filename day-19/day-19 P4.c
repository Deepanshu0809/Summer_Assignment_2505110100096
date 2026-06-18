#include <stdio.h>
int main() {
    int n, i, j;
    int principal_sum = 0, secondary_sum = 0;

    printf("Enter the size of the square matrix (N x N): ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    
    for (i = 0; i < n; i++) {
        principal_sum += matrix[i][i];            
        secondary_sum += matrix[i][n - i - 1];    
    }
    printf("\nSum of Principal Diagonal: %d\n", principal_sum);
    printf("Sum of Secondary Diagonal: %d\n", secondary_sum);

    return 0;
}