#include <stdio.h>
int find_max(int num1, int num2);

int main() {
    int a, b, max_val;
    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Invalid input.\n");
        return 1;
    }
    max_val = find_max(a, b);
    printf("The maximum number is: %d\n", max_val);

    return 0;
}
int find_max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}