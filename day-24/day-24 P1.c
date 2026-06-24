#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool areRotations(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2) {
        return false;
    }

    char temp[len1 * 2 + 1];

    strcpy(temp, str1);
    strcat(temp, str1);

    if (strstr(temp, str2) != NULL) {
        return true;
    }

    return false;
}

int main() {
    char str1[] = "ABCD";
    char str2[] = "CDAB";

    if (areRotations(str1, str2)) {
        printf("\"%s\" is a rotation of \"%s\"\n", str2, str1);
    } else {
        printf("\"%s\" is NOT a rotation of \"%s\"\n", str2, str1);
    }

    return 0;
}