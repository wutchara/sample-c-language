#include <stdio.h>

int main() {
    int n;
    printf("Enter number(n):");
    scanf("%d", &n);

    // find the sum
    int sum = 0;

    // find the product
    int product = 0; // support n <= 0

    if(n > 0) {
        product = 1;
    }

    int i;
    for (i = 1; i <= n; i++) {
        product *= i;
        sum += i;
    }

    printf("Yor number:%d\nYou Sum result:%d\nYou Product result:%d\n", n, sum, product);

    return 0;
}