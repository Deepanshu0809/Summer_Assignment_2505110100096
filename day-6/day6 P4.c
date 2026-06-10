#include <stdio.h>

int main() {
    double base, result = 1.0;
    int exponent, abs_exponent;

    
    printf("Enter base (x): ");
    scanf("%lf", &base);
    printf("Enter exponent (n): ");
    scanf("%d", &exponent);

  
    abs_exponent = (exponent < 0) ? -exponent : exponent;
    for (int i = 0; i < abs_exponent; i++) {
        result *= base;
    }

    if (exponent < 0) {
        result = 1.0 / result;
    }

   
    printf("%.2lf raised to the power of %d is: %.6lf\n", base, exponent, result);

    return 0;
}