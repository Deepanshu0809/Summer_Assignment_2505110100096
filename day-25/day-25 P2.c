#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "portfolio";
    char str2[] = "courses";
    
    int present[256] = {0};
    
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("Common characters: ");

    for (int i = 0; str1[i] != '\0'; i++) {
       
        present[(unsigned char)str1[i]] = 1;
    }

    for (int i = 0; str2[i] != '\0'; i++) {
        unsigned char ch = str2[i];
        
        if (present[ch] == 1) {
            printf("%c ", ch);
            
            present[ch] = 2; 
        }
    }
    
    printf("\n");
    return 0;
}