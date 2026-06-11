#include <stdio.h>

int main() {
    int rows = 5; 
    for (int i = 1; i <= rows; i++) {
        for (char ch = 'A'; ch < 'A' + i; ch++) {
            printf("%c", ch);
        }
        printf("\n");
    }

    return 0;
}