#include <stdio.h>
unsigned long long findFactorial(int n);

int main() {
    int num;
    unsigned long long fact;

    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Error: Factorial of a negative number does not exist.\n");
    } else {
        fact = findFactorial(num);
        printf("Factorial of %d = %llu\n", num, fact);
    }

    return 0;
}
unsigned long long findFactorial(int n) {
    unsigned long long result = 1;
    
    for (int i = 1; i <= n; i++) {
        result *= i; 
    }
    return result;
}
