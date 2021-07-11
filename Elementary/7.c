#include <stdio.h>

int main() {
    printf("---------- Multiplication table ----------\n");
    int n = 12;
    int i;
    for (i = 2; i <= n; i++) {
        // Create table
        printf("--------------- %d ---------------\n", i);
        printf("----------------------------------\n");
        int j;
        for (j = 1; j <= 12; j++) {
            printf("%d\tx\t%d\t=\t%d\n", i, j, i*j);
        }
        printf("----------------------------------\n");
    }

    return 0;
}