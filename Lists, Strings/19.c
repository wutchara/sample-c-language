#include <stdio.h>

int arrSize = 0;
const int MAX_STRING_LENGTH = 10;

int findMaxstringIndex(char str[]) {
    int totChar = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        totChar++;
    }
    return totChar;
}

void printStar(int number) {
    for (int i = 0; i < number; i++) {
        printf("%c", '*');
    }
}

void printStarFrame(int number) {
    printStar(number);
    printf("\n");
}

void printStringFrame(char list[arrSize][MAX_STRING_LENGTH]) {
    int starLength = 0;
    // find max string to generate '*'
    for (int i = 0; i < arrSize; i++) {
        int strLength = findMaxstringIndex(list[i]);

        if (strLength > starLength) {
            starLength = strLength;
        }
    }
    starLength += 4;// add space, e.g. **XXXXXXXX**
    printStarFrame(starLength);

    for (int i = 0; i < arrSize; i++) {
        printf("* %s", list[i]);

        int strLength = findMaxstringIndex(list[i]);
        int remainSpaces = starLength - strLength - 4;// 2 before the string and 2 is after the string
        for (int j = 0; j < remainSpaces; j++) {
            printf(" ");
        }
        printf(" *\n");
    }

    printStarFrame(starLength);
}

int main() {
    // '10' is length of a string
    char strList[][10] = { "Hello", "World", "in", "a" };
    arrSize =  sizeof(strList)/sizeof(strList[0]);
    printStringFrame(strList);

    return 0;
}