#include <stdio.h>
#include <stdlib.h>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printL(long arr[], int n) {
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

void getDigitsAdd(long n, int size, int digits[], int *digitsAdd) {
    for (int i = 0; i < size; i++) {
        digitsAdd[i] = n + digits[i];
    }
}

void getDigitsSubtract(long n, int size, int digits[], int *digitsSubtract) {
    for (int i = 0; i < size; i++) {
        digitsSubtract[i] = n - digits[i];
    }
}

void getDigitsMultiply(long n, int size, int digits[], long *digitsMultiply) {
    for (int i = 0; i < size; i++) {
        digitsMultiply[i] = digits[i] * n;
    }
}

int main() {
    long number = 23425;
    int size = getDigitNumber(number);
    printf("Number: %ld(%d digits)\n", number, size);

    int digits[size]; // Parse by reference
    getDigits(number, size, digits);
    printf("Result separate digits:\n");
    print(digits, size);


    int digitsAdd[size];
    printf("\nResult add digits:\n");
    getDigitsAdd(number, size, digits, digitsAdd);
    print(digitsAdd, size);

    int digitsSubtract[size];
    printf("\nResult subtract digits:\n");
    getDigitsSubtract(number, size, digits, digitsSubtract);
    print(digitsSubtract, size);

    
    long digitsMultiply[size];
    printf("\nResult multiply digits:\n");
    getDigitsMultiply(number, size, digits, digitsMultiply);
    printL(digitsMultiply, size);

    return 0;
}