#include <stdio.h>


void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sumForLoop(int arr[], int size) {
    int i;
    int sum = 0;
    for(i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int sumWhileLoop(int arr[], int size) {
    int i = 0;
    int sum = 0;
    while (i < size) {
        sum += arr[i];
        i++;
    }
    return sum;
}

int sumRecursion(int arr[], int size, int index) {
    if (index == size - 1) {
        return arr[index];
    } else {
        return arr[index] + sumRecursion(arr, size, index + 1);
    }
return 0;
}

int main() {
    int lists[] = {1, 2, 3, 4, 55, 6, 7, 8, 9};
    int size = sizeof(lists)/sizeof(lists[0]);
    printf("Lists:\n");
    print(lists, size);

    printf("Get sum in For-Loop: %d\n", sumForLoop(lists, size));
    printf("Get sum in While-Loop: %d\n", sumWhileLoop(lists, size));

    int index = 0;
    printf("Get sum in Recursion: %d\n", sumRecursion(lists, size, index));
    return 0;
}