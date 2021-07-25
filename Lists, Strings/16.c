#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printResult(int arr[], int n, int b1, int b2) {
    printf("\nResult convert base-%d to base-%d:\nBase-%d => ", b1, b2, b2);
    print(arr, n);
}

void getDigits(int n, int size, int *digits) {
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

// convert int to char
char reVal(int num) {
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

// Utility function to reverse a string
void strev(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

// Function to convert a given decimal number
// to a base 'base' and
char* fromDeci(char res[], int base, int inputNum) {
    int index = 0;  // Initialize index of result

    // Convert input number is given base by repeatedly
    // dividing it by base and taking remainder
    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0'; // EOF

    // Reverse the result
    strev(res);

    return res;
}

void convertBaseNumber(int arr[], int size, int b1, int b2) {
    int result10Base = 0; // result in '10' base
    int degree = 0;
    for (int i = (size - 1); i >= 0; i--) {
        result10Base += arr[i] * pow(b1, degree++);
    }

    // convert to 'b2' base
    if (b2 != 10) {
        char res[100];
        fromDeci(res, b2, result10Base);
        long b2Value = atoi(res);
        int b2Size = getDigitNumber(b2Value);
        int resultB2Arr[b2Size];

        getDigits(b2Value, b2Size, resultB2Arr);
        printResult(resultB2Arr, b2Size, b1, b2);
    } else {
        // base 10
        int b2Size = getDigitNumber(result10Base);
        int resultB2Arr[b2Size];

        getDigits(result10Base, b2Size, resultB2Arr);
        printResult(resultB2Arr, b2Size, b1, b2);
    }
}

int main() {
    int lists[] = {2, 1, 0};
    int base1 = 3, base2 = 10, size = sizeof(lists)/sizeof(lists[0]);
    printf("lists:\nBase-%d => ", base1);
    print(lists, size);
    convertBaseNumber(lists, size, base1, base2);

    printf("\n------------------------\n");

    int base3 = 8;
    printf("lists:\nBase-%d => ", base1);
    print(lists, size);
    convertBaseNumber(lists, size, base1, base3);

    return 0;
}