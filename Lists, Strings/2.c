#include <stdio.h>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void reverse(int arr[], int n) {
    int aux[n];
    for (int i = 0; i < n; i++) {
        aux[n - 1 - i] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = aux[i];
    }
}


int main() {
    int lists[] = {1, 2, 3, 4, 55, 6, 7, 8, 9};
    int size = sizeof(lists)/sizeof(lists[0]);
    printf("\nOriginal Array\n");
    print(lists, size);

    printf("\nReverse Array\n");
    reverse(lists, size);
    print(lists, size);

    return 0;
}