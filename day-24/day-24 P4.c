#include <stdio.h>
#include <string.h>

void removeDuplicates(char* str) {
    
    int seen[256] = {0}; 
    
    int readIndex = 0;
    int writeIndex = 0;

    
    while (str[readIndex] != '\0') {
        char currentChar = str[readIndex];

        
        if (seen[(unsigned char)currentChar] == 0) {
            seen[(unsigned char)currentChar] = 1; 
            str[writeIndex] = currentChar;        
            writeIndex++;                     
        }
        readIndex++; 
    }

    str[writeIndex] = '\0'; 
}

int main() {
    
    char str[] = "programming"; 
    
    printf("Original String: %s\n", str);
    
    removeDuplicates(str);
    
    printf("String after removing duplicates: %s\n", str);
    
    return 0;
}