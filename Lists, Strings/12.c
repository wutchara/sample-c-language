#include <stdio.h>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void rotatesArray(int *lists, int size) {
    int i, temp, swapCount = 0;
    for (i = 0; i < size - 2; i++) {
        temp = lists[i + 2];
        lists[i + 2] = lists[i];
        lists[i] = temp;
        swapCount++;
    }
    printf("\n---------Swap Count: %d---------\n", swapCount);
}

int main() {
    int lists[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(lists)/sizeof(lists[0]);
    printf("-----------------ORIGINAL---------------------\n");
    print(lists, size);
    printf("-----------------ROTAGES---------------------\n");
    int mergedArr[size]; // Parse by reference
    rotatesArray(lists, size);
    print(lists, size);
    return 0;
}