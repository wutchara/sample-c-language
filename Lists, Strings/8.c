#include <stdio.h>

void on_all(int num) {
    int i;
    for (i = num; i <= num + 20; i++) {
        printf("%d\t", i * i);
    }
}

void printLists(int lists[], int size) {
    int i;
    for ( i = 0; i < size; i++) {
        printf("\n%d.> -------- %d --------\n", i+1, lists[i]);
        on_all(lists[i]);
        printf("\n----------------\n");
    }
}

int main() {
    int lists[] = {1, 2, 3};
    int size = sizeof(lists)/sizeof(lists[0]);
    printLists(lists, size);
    
    return 0;
}