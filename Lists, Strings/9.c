#include <stdio.h>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* concatenatesLists(int lists1[], int size1, int lists2[], int size2, int *mergedLists) {
    int i;
    for (i = 0; i < size1; i++) {
        mergedLists[i] = lists1[i];
    }

    for (i = size1; i < (size1 + size2); i++) {
        mergedLists[i] = lists2[i - size1];
    }

    return mergedLists;
}

int main() {
    int lists1[] = {1, 2, 3};
    int lists2[] = {4, 5, 6, 7};

    int size1 = sizeof(lists1)/sizeof(lists1[0]);
    int size2 = sizeof(lists2)/sizeof(lists2[0]);
    int newSize = size1 + size2;

    int mergedArr[newSize]; // Parse by reference
    int *n;  // Test receive return value
    n = concatenatesLists(lists1, size1, lists2, size2, mergedArr);
    printf("------- mergedArr -------\n");
    print(mergedArr, newSize);
    printf("------- n -------\n");
    print(n, newSize);
    printf("-----------------\n");
    
    
    // 'n' and 'mergedArr' are the same address e.g.
    printf("n[1] :%d,mergedArr[1] :%d,\n", n[1], mergedArr[1]);
    mergedArr[1] = 9;
    printf("NEW => n[1] :%d,mergedArr[1] :%d,\n", n[1], mergedArr[1]);
    
    return 0;
}