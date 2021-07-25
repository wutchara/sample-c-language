#include <stdio.h>
#include <stdlib.h>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void getDigits(long n, int size, int *digits) {
    char splitNumbers[size];
    itoa(n, splitNumbers, 10); // 'int' to 'char[]' in number base-10

    for (int i = 0; i < size; i++) {
        digits[i] = splitNumbers[i] - '0'; // convert 'char' to 'int'
    }
}

int getDigitNumber(long n) {
    int count = 0;
    while(n!=0)  
    {  
        n=n/10;  
        count++;  
    }
    return count;
}

int main() {
    long number = 23425;
    int size = getDigitNumber(number);
    printf("Number: %ld(%d digits)\n", number, size);

    int digits[size]; // Parse by reference
    getDigits(number, size, digits);
    printf("Result separate digits:\n");
    print(digits, size);

    return 0;
}