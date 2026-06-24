#include <stdio.h>
int main() {
    int rows, cols;
    int matrix[10][10];
    int isSymmetric = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows != cols) {
        printf("The matrix must be a square matrix (rows must equal columns).\n");
        return 0;
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0; 
                break;
            }
        }
        if (!isSymmetric) {
            break;
        }
    }

    if (isSymmetric) {
        printf("The matrix is Symmetric.\n");
    } else {
        printf("The matrix is NOT Symmetric.\n");
    }
    return 0;
}