#include <stdio.h>

int main() 
{  
    int arr[] = {12, 5, 45, 93, 2, 67};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i]; 
        }
        if (arr[i] < min) {
            min = arr[i]; 
        }
    }
    printf("Largest element: %d\n", max);
    printf("Smallest element: %d\n", min);
    
    return 0;
}