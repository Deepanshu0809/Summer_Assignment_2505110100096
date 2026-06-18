#include <stdio.h>
int main() 
{
    int arr[] = {4, 2, 7, 4, 7, 5, 7, 4, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxElement = arr[0];
    int maxCount = 0;
    for (int i = 0; i < size; i++) {
        int currentCount = 0;
        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                currentCount++;
            }
        }
        if (currentCount > maxCount) {
            maxCount = currentCount;
            maxElement = arr[i];
        }
    }
    printf("Element with maximum frequency: %d\n", maxElement);
    printf("It appears %d times.\n", maxCount);

    return 0;
}