#include <stdio.h>

int sum(int endNumber) {
    if (endNumber == 1) {
        return 1;
    } else if (endNumber < 1) {
        return endNumber;
    } else {
        return endNumber + sum(endNumber - 1);
    }
}

int main() {
    int n;
    printf("Enter number(n) to Calculate the sum of number 1 to n:");
    scanf("%d", &n);

    // #1 Use Recursive function
    printf("-------------------- Method #1 --------------------\n");
    printf("Yor number:%d\nYou result:%d\n", n, sum(n));

    // #2 Usd the loop
    printf("-------------------- Method #2 --------------------\n");
    int sum = 0;
    int i;
    for (i = 0; i <= n; i++) {
        sum += i;
    }
    printf("Yor number:%d\nYou result:%d\n", n, sum);

    return 0;
}