#include <stdio.h>
#include <string.h>

void compressString(char *str) {
    int length = strlen(str);
    
    for (int i = 0; i < length; i++) {
        
        int count = 1;
        while (i < length - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        
        printf("%c%d", str[i], count);
    }
    printf("\n");
}

int main() {
    char str[100];
    
    printf("Enter a string to compress: ");
    scanf("%99s", str); 
    
    printf("Compressed string: ");
    compressString(str);
    
    return 0;
}