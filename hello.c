#include <stdio.h>
void printSpaceNewLine();

// Declaration of enum
typedef enum { F, T } boolean;

struct SubBook {
    char  title[50];
    char  author[50];
};

struct Books {
    char  title[50];
    char  author[50];
    char  subject[100];
    int   book_id;
    struct SubBook subbook;
};

const char* getStringByBoolean(boolean b) {
    if (b) {
        return "True";
    } else {
        return "False";
    }
}

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

    int a = 5, b = 10;
    printf("a+b:%d\n", a+b);
    printf("a-b:%d\n", a-b);
    printf("a*b:%d\n", a*b);
    printf("a/b:%.2f\n", a/(float)b);
    printf("a mod b:%d\n", a%b);

    printf("a == b:%s\n", getStringByBoolean(a == b));
    printf("a == 5:%s\n", getStringByBoolean(a == 5));
    printf("a != b:%s\n", getStringByBoolean(a != b));
    printf("a > b:%s\n", getStringByBoolean(a > b));
    printf("a < b:%s\n", getStringByBoolean(a < b));
    printf("a >= b:%s\n", getStringByBoolean(a >= b));
    printf("a <= b:%s\n", getStringByBoolean(a <= b));

    printf("TRUE AND TRUE:%s\n", getStringByBoolean((1 == 1) && (2 == 2)));
    printf("TRUE AND FALSE:%s\n", getStringByBoolean((1 == 1) && (2 == 3)));
    printf("TRUE OR FALSE:%s\n", getStringByBoolean((1 == 1) || (2 == 3)));
    printf("TRUE:%s\n", getStringByBoolean(1 == 1));
    printf("NOT TRUE:%s\n", getStringByBoolean(!(1 == 1)));

    int x = 10;
    printf("x:%d\n", x);

    x -= 1;
    printf("x:%d\n", x);

    x += 10;
    printf("x:%d\n", x);
    printf("x:%p\n", &x);

    int *y = 10;
    y = 5;
    printf("y:%d\n", y);

    int yArr[5] = {1, 2, 3, 4, 5};
    printf("yArr:%d\n", yArr[1]);
    printf("yArr:size:%d\n", sizeof(yArr));
    printSpaceNewLine();

    int sum = 0;
    int index = 0;
    while(sum < 5) {
        printf("while-loop:index(%d):value(%d):sum:%d\n", index, yArr[index], sum);
        sum += yArr[index++];
    }

    printSpaceNewLine();

    sum = 0;
    index = 0;
    do {
        printf("do-while-loop:index(%d):value(%d):sum:%d\n", index, yArr[index], sum);
        sum += yArr[index++];
    } while(sum < 5);

    printSpaceNewLine();

    int i;
    sum = 0;
    for( i = 0; sum < 5; i++) {
        printf("for-loop:index(%d):value(%d):sum:%d\n", i, yArr[i], sum);
        sum += yArr[i];
    }


    printSpaceNewLine();
    struct Books Book1;
    strcpy( Book1.subbook.title, "title C Programmingssssss");
    strcpy( Book1.subbook.author, "author C Programmingssssss");


    strcpy( Book1.title, "C Programming");
    strcpy( Book1.author, "HAM"); 
    strcpy( Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495407;

    /* print Book1 info */
    printf( "Book 1 title : %s\n", Book1.title);
    printf( "Book 1 author : %s\n", Book1.author);
    printf( "Book 1 subject : %s\n", Book1.subject);
    printf( "Book 1 book_id : %d\n", Book1.book_id);
    printf( "Book 1 subbook title : %s\n", Book1.subbook.title);
    printf( "Book 1 subbook author : %s\n", Book1.subbook.author);
    return 0;
}

void printSpaceNewLine() {
    printf("-----------------\n");
}
