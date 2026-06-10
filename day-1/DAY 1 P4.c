#include <stdio.h>

int main() {
    long long num;
    int count = 0;
    printf("Enter an integer: ");
    scanf("%lld", &num);

    long long temp = num;

    do {
        count++;
        temp /= 10; 
    } while (temp != 0);

    printf("The number %lld has %d digits.\n", num, count);

    return 0;
}