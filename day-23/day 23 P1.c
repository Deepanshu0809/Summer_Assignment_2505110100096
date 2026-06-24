#include <stdio.h>

int main() {
    char str[] = "datastructures";
    int count[256] = {0}; 
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[str[i]]]++; 
    }

    for (i = 0; str[i] != '\0'; i++) {
        if (count[(unsigned char)str[i]] == 1) {
            printf("The first non-repeating character is: %c\n", str[i]);
            return 0; 
        }
    }
    printf("All characters repeat or the string is empty.\n");
    return 0;
}