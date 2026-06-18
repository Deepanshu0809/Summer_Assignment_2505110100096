#include <stdio.h>

int main() {
    int arr[] = {4, 2, 4, 3, 2, 5, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]); 

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
           
            if (arr[i] == arr[j]) {
        
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
               
                size--;
                j--; 
            }
        }
    }
    printf("Array after removing duplicates: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}