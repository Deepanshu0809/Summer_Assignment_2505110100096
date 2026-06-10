#include <stdio.h>

int main() {
    int num, remainder, sum = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    while (num != 0) {
        remainder = num % 10;  
        sum += remainder;      
        num = num / 10;        
    }

    printf("Sum of digits = %d\n", sum);

    return 0;
}