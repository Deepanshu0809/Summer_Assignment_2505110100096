#include <stdio.h>

int main() {
    
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int rows = 3;
    int cols = 3;
    int sum;

    printf("Matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nCalculating Row-wise Sum:\n");
    for (int i = 0; i < rows; i++) {
        sum = 0; 
        

        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j]; 
        }
        
        printf("Sum of Row %d = %d\n", i + 1, sum);
    }

    return 0;
}