#include <stdio.h>

int main() {
    
    int a[2][2] = {{1, 2}, 
                   {3, 4}};
                   
    int b[2][2] = {{5, 6}, 
                   {7, 8}};
                   
    int result[2][2] = {0}; 
    
    
    int i, j, k;

    
    for (i = 0; i < 2; i++) {        
        for (j = 0; j < 2; j++) {     
            for (k = 0; k < 2; k++) { 
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    printf("Resultant Matrix:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}

