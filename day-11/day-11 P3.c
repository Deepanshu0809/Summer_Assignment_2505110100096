#include<stdio.h>

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (checkPrime(num) == 1) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}