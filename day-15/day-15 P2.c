#include <stdio.h>
void rotateLeftByOne(int arr[], int size)
 {
    int temp = arr[0]; 
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = temp; 
}
void rotateLeft(int arr[], int d, int size) {
    d = d % size; 
    for (int i = 0; i < d; i++) {
        rotateLeftByOne(arr, size);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int rotations = 2; 

    printf("Original Array: ");
    printArray(arr, size);
    rotateLeft(arr, rotations, size);
    printf("Array after %d left rotations: ", rotations);
    printArray(arr, size);

    return 0;
}