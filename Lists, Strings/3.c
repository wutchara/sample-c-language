#include <stdio.h>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 0 is notfound, 1 is found
int hasInLists(int target, int arr[], int size) {
    int isFound = 0;
    int i;
    for (i = 0; i < size; i++) {
        if (target == arr[i]) {
            isFound = 1;
            break;
        }
    }
    return isFound;
}

void printFoundInList(int target, int arr[], int size) {
    int result = hasInLists(target, arr, size);
    printf("'%d' is %sfound in array lists.\n", target, result == 0 ? "not " : "");
}

int main() {
    int lists[] = {1, 2, 3, 4, 55, 6, 7, 8, 9};
    int size = sizeof(lists)/sizeof(lists[0]);
    printf("Lists:\n");
    print(lists, size);

    printFoundInList(5, lists, size);
    printFoundInList(55, lists, size);

    return 0;
}