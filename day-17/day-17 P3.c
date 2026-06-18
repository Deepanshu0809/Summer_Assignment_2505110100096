#include <stdio.h>

int main() {

    int array1[] = {4, 9, 5, 4, 1};
    int array2[] = {9, 4, 9, 8, 4};

    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    
    
    int intersection[100]; 
    int k = 0; 

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {

            if (array1[i] == array2[j]) {
            
                int isDuplicate = 0;
                for (int m = 0; m < k; m++) {
                    if (intersection[m] == array1[i]) {
                        isDuplicate = 1;
                        break;
                    }
                }
                if (!isDuplicate) {
                    intersection[k] = array1[i];
                    k++;
                }
                break; 
            }
        }
    }
    printf("Intersection of the two arrays: ");
    if (k == 0) {
        printf("No common elements found.");
    } else {
        for (int i = 0; i < k; i++) {
            printf("%d ", intersection[i]);
        }
    }
    printf("\n");

    return 0;
}