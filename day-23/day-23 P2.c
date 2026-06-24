#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int found = 0;

    printf("Enter a string: ");
    
    scanf("%[^\n]", str); 

    int length = strlen(str);

    
    for (int i = 0; i < length; i++) {
        
        for (int j = i + 1; j < length; j++) {
            if (str[i] == str[j]) {
                printf("The first repeating character is: '%c'\n", str[i]);
                found = 1;
                break;
            }
        }
        
        if (found) {
            break; 
        }
    }
    if (!found) {
        printf("No repeating characters found.\n");
    }

    return 0;
}