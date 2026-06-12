#include <stdio.h>

void printFibonacci(int terms);

int main() {
    int num_terms;
    printf("Enter the number of terms for the Fibonacci series: ");
    if (scanf("%d", &num_terms) != 1 || num_terms <= 0) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }
    printFibonacci(num_terms);

    return 0;
}
void printFibonacci(int terms) {
    long long first = 0, second = 1, next;

    printf("Fibonacci Series (%d terms): ", terms);

    for (int i = 1; i <= terms; i++) {
        printf("%lld ", first);
        next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
}