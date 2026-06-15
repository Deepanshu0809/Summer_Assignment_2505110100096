#include <stdio.h>
int main() 
{
    int arr[] = {2, 5, 3, 2, 8, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 2; 
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    printf("The element %d appears %d times.\n", target, count);
    return 0;
}