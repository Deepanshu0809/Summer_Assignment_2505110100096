#include <stdio.h>
int main() 
{
    int array[100], target, i, n;
    int found = 0; 
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter a number to search: ");
    scanf("%d", &target);
    for (i = 0; i < n; i++) {
        if (array[i] == target) {
            printf("%d is found at index position %d.\n", target, i);
            found = 1; 
            break;  
        }
    }
    if (found == 0) {
        printf("%d is not present in the array.\n", target);
    }
    return 0;
}