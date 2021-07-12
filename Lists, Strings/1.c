#include <stdio.h>

int getLargestNumber(int lists[], int size) {
    int maxNum = lists[0];
    int i;
    for (i = 0; i < size; i++) {
        if (lists[i] > maxNum) {
            maxNum = lists[i];
        }
    }

    return maxNum;
}

int main() {
    int lists[] = {1, 2, 3, 4, 55, 6, 7, 8, 9};
    int size = sizeof(lists)/sizeof(lists[0]);
    printf("the largest element:%d\n", getLargestNumber(lists, size));

    return 0;
}