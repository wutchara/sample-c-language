#include <stdio.h>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void getOddPosition(int arr[], int size, int newArr[]) {
    int i;
    int lastIndex = 0;
    for (int i = 0; i < size; i++) {
        if (i%2 == 1) {
            newArr[lastIndex] = arr[i];
            lastIndex++;
        }
    }
}

int main() {
    int lists[] = {1, 2, 3, 4, 55, 6, 7, 8, 9};
    int size = sizeof(lists)/sizeof(lists[0]);
    printf("Lists:\n");
    print(lists, size);

    int oddArr[size/2];

    getOddPosition(lists, size, oddArr);
    printf("New Lists in odd position:\n");
    print(oddArr, size/2);

    return 0;
}