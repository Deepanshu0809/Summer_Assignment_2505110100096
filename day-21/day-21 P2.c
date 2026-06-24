#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int start = 0;
    int end;
    char temp;


    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);


    str[strcspn(str, "\n")] = '\0';


    end = strlen(str) - 1;

    
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}