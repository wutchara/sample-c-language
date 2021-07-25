#include <stdio.h>

void print(unsigned long long arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generateFibonacci(int size, unsigned long long *lists) {
    if (size > 0) {
        int index = 0;
        do {
            if (index == 0) {
                lists[index] = 1;
            } else if (index == 1) {
                lists[index] = 1;
            } else {
                lists[index] = lists[index-1] + lists[index-2];
            }
            index++;
        } while(index < size);
    }
}

unsigned long long getFibonacci(int n) {
    if (n >= 47) { // TODO: Maximum
        return 0;
    }

    if (n <= 2) {// f1, f2 = 1
        return 1;
    } else {
        return getFibonacci(n - 1) + getFibonacci(n - 2);
    }
}

int main() {
    int size = 100;
    printf("Generate Fibonacci number(%d): \n", size);
    unsigned long long lists[size];
    generateFibonacci(size, lists);
    print(lists, size);

    printf("\n===================================================\n");
    for (int i = 1; i <= size; i++) {
        printf("%d.>:\t%d\n", i, getFibonacci(i));
    }

    return 0;
}