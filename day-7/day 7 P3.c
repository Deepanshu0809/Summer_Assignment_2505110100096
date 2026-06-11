#include <stdio.h>

int sumOfDigits(int num) {
    if (num == 0) {
        return 0;
    }
    
    return (num % 10) + sumOfDigits(num / 10);
}

int main() {
    int number, result;

    printf("Enter an integer: ");
    scanf("%d", &number);

    result = sumOfDigits(number);

    printf("Sum of digits: %d\n", result);

    return 0;
}