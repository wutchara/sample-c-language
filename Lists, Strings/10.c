#include <stdio.h>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Assume they arrays are the same length
int* combines(int lists1[], int size1, int lists2[], int size2, int *mergedLists) {
    int i = 0, j = 0, lastIndex = 0;
    do {
        mergedLists[lastIndex++] = lists1[i++];
        mergedLists[lastIndex++] = lists2[j++];
    } while(i < size1);

    return mergedLists;
}

int* combinesAdv(int lists1[], int size1, int lists2[], int size2, int *mergedLists) {
    // Find th gathest array size
    int newSize = size1 + size2;
    int i = 0, j = 0, lastIndex = 0;
    do {
        // for 'list1'
        if (i < size1) {
            mergedLists[lastIndex++] = lists1[i++];
        } else if (j < size2) {
            mergedLists[lastIndex++] = lists2[j++];
        }

        // for 'list2'
        if (j < size2) {
            mergedLists[lastIndex++] = lists2[j++];
        } else if (i < size1) {
            mergedLists[lastIndex++] = lists1[i++];
        }
    } while(lastIndex < newSize);

    return mergedLists;
}

int main() {
    int lists1[] = {1, 2, 3};
    int lists2[] = {4, 5, 6};

    int size1 = sizeof(lists1)/sizeof(lists1[0]);
    int size2 = sizeof(lists2)/sizeof(lists2[0]);
    int newSize = size1 + size2;

    int mergedArr[newSize]; // Parse by reference
    int *n;  // Test receive return value
    n = combines(lists1, size1, lists2, size2, mergedArr);
    printf("------- mergedArr -------\n");
    print(mergedArr, newSize);
    printf("------- n -------\n");
    print(n, newSize);
    printf("-----------------\n");


    int lists3[] = {4, 5, 6, 7, 8, 9};
    int size3 = sizeof(lists3)/sizeof(lists3[0]);
    int newSize2 = size1 + size3;
    int mergedArr2[newSize2];
    combinesAdv(lists1, size1, lists3, size3, mergedArr2);
    printf("------- mergedArr2 -------\n");
    print(mergedArr2, newSize2);
    printf("-----------------\n");
    return 0;
}