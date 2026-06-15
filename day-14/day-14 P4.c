#include <stdio.h>
int main() 
{
    int arr[] = {2, 4, 6, 2, 8, 4, 10, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Duplicate elements in the array are: \n");
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            
            if (arr[i] == arr[j]) {
                printf("%d\n", arr[j]);
                break;
            }
        }
    }

    return 0;
}