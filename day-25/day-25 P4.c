#include <stdio.h>
#include <string.h>

int main() {

    char words[5][20] = {"Elephant", "Cat", "Banana", "Dog", "Ant"};
    char temp[20];
    int n = 5;

    printf("Original words:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
           
            if (strlen(words[j]) > strlen(words[j + 1])) {
            
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    printf("\nWords sorted by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}