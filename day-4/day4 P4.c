#include <stdio.h>
#include <math.h>

int main() {
    int start, end, i, temp, remainder, digits, sum;

    printf("Enter starting number: ");
    scanf("%d", &start);
    printf("Enter ending number: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are:\n", start, end);

    for (i = start; i <= end; i++) {
        digits = 0;
        temp = i;
        while (temp != 0) {
            temp /= 10;
            digits++;
        }

        sum = 0;
        temp = i;
        while (temp != 0) {
            remainder = temp % 10;
            sum += round(pow(remainder, digits)); 
            temp /= 10;
        }
        if (sum == i) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
