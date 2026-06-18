#include <stdio.h>

int main() {
    int arr1[] = {10, 20, 30};
    int arr2[] = {40, 50, 60, 70};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int mergedSize = size1 + size2;
    int merged[mergedSize];
    
    int i;
    for (i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    for (i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }
    printf("Merged Array: ");
    for (i = 0; i < mergedSize; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}