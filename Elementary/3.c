#include <stdio.h>
#include<string.h>  

int main() {
    char str[100];
    printf("Enter You Name:");
    gets(str);

    if (strcmp(str,"Alice") == 0 || strcmp(str,"Bob") == 0) {
        printf("Welcome:%s\n", str);
    } else {
        printf("..........., %s", str);
    }

    return 0;
}