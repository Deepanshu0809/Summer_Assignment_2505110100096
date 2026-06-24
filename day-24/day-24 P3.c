#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char longest[50] = "";
    char current[50] = "";
    int i, j = 0;

    printf("Enter a sentence: ");
    
    fgets(str, sizeof(str), stdin); 


    str[strcspn(str, "\n")] = '\0';

    for (i = 0; i <= strlen(str); i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            current[j++] = str[i];
        } 
        
        else {
            current[j] = '\0'; 

            if (strlen(current) > strlen(longest)) {
                strcpy(longest, current);
            }
            j = 0; 
        }
    }

    printf("The longest word is: %s\n", longest);
    printf("Length: %lu\n", strlen(longest));

    return 0;
}