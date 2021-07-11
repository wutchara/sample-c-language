#include <stdio.h>

int main() {
    int n;
    printf("Enter number(n) to Calculate the sum of number 1 to n:");
    scanf("%d", &n);

    int sum = 0;
    int i;
    // find array of 3
    for (i = 0; i <= n; i += 3) {
        sum += i;
        // printf("i3:%d\n", i);
    }

    // find array of 5
    for (i = 0; i <= n; i += 5) {
        // Avoid duplicate number of the 3 series
        if (i % 3 != 0) {
            sum += i;
            // printf("i5:%d\n", i);
        }
    }

    printf("Yor number:%d\nYou result:%d\n", n, sum);

    return 0;
}