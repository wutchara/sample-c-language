#include <stdio.h>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* mergeSorted(int lists1[], int size1, int lists2[], int size2, int *mergedLists) {
    // Find th gathest array size
    int newSize = size1 + size2;
    int index1 = 0, index2 = 0, lastIndex = 0;
    do {
        if (index1 >= size1) {
            // empty list1
            mergedLists[lastIndex++] = lists2[index2++];
        } else if (index2 >= size2) {
            // empty list2
            mergedLists[lastIndex++] = lists1[index1++];
        } else {
            // check value when normally index
            mergedLists[lastIndex++] = lists1[index1] < lists2[index2] ? lists1[index1++] : lists2[index2++];
        }
    } while(lastIndex < newSize);

    return mergedLists;
}

int main() {
    int lists1[] = {1, 3, 12};
    int lists2[] = {2, 3, 6, 8, 10, 15};

    int size1 = sizeof(lists1)/sizeof(lists1[0]);
    int size2 = sizeof(lists2)/sizeof(lists2[0]);
    int newSize = size1 + size2;

    int mergedArr[newSize]; // Parse by reference
    int *n;  // Test receive return value
    n = mergeSorted(lists1, size1, lists2, size2, mergedArr);

    printf("------- List 1 -------\n");
    print(lists1, size1);
    printf("------- List 2 -------\n");
    print(lists2, size2);
    printf("------- mergedArr -------\n");
    print(n, newSize);
    printf("-----------------\n");
    return 0;
}