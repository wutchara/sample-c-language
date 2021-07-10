#include <stdio.h>
void printSpaceNewLine();

#define WIDTH  5

// global and assign default value into this varable
int num;

int main() {
    printf("Hello Ja....\n");
    int count = 0;
    printf("Count:%d\n", count);

    count = count + 1;
    printf("Count:%d\n", count); // 1
    // printf("Count++:%d\n", count++);
    printf("++Count:%d\n", ++count);
    printf("Count:%d\n", count);
    printSpaceNewLine();

    char c = 'x';
    char cc = 'xy';
    char s[] = "xy";
    printf("C:%c\n", c);
    printf("CC:%c\n", cc);
    printf("S:%s\n", s);
    printSpaceNewLine();

    float f = 1.65;
    printf("f:%.1f\n", f);
    double df = 10.6;
    printf("f:%f\n", df);

    int iff = 1;
    printf("i=>f:%f,%d\n", (float) iff, iff);

    
    num = 99;
    printf("NUM:%d\n", num);
    printf("WIDTH:%d\n", WIDTH);

    return 0;
}

void printSpaceNewLine() {
    printf("-----------------\n");
}
