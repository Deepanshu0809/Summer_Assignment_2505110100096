#include <stdio.h>
int main() {
    int arr[] = {1, 0, 3, 0, 12, 0, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    moveZeroesToEnd(arr, size);
    printf("\nModified array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}