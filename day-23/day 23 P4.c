#include <stdio.h>

int main() {
    char str[100];
    int freq[256] = {0}; 
    int i, max_index;

    printf("Enter a string: ");
   
    scanf("%[^\n]", str); 

    for (i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    max_index = 0;
    for (i = 0; i < 256; i++) {
      
        if (i != ' ' && freq[i] > freq[max_index]) {
            max_index = i;
        }
    }

    printf("The maximum occurring character is '%c' (appears %d times).\n", max_index, freq[max_index]);

    return 0;
}