#include <stdio.h>

int countSetBitsSimple(unsigned int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

int main() {
    unsigned int num = 29; 
    printf("Number of set bits in %u is %d\n", num, countSetBitsSimple(num));
    return 0;
}