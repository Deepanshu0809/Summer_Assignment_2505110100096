#include <stdio.h>

int main() {
    int arr[5];
    int i;
    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]); 
    }
    printf("\nThe elements in the array are:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n");
    return 0;
}