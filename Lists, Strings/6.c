#include <stdio.h>
#include<string.h>  

// 0 is false, 1 is true
int checkPalindrome(char str[]) {
    int isPalindrome = 1;
    int start = 0;
    int end = strlen(str) - 1;

    while (end > start) {
        if (str[start++] != str[end--]) {
            isPalindrome = 0;
            break;
        }
    }
    return isPalindrome;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    gets(str);

    printf("Your string is %sa palindrome.", checkPalindrome(str) == 0 ? "not " : "");

    return 0;
}