#include <stdio.h>
#include <time.h>

/*
How to determine whether a year is a leap year

To determine whether a year is a leap year, follow these steps:
    1. If the year is evenly divisible by 4, go to step 2. Otherwise, go to step 5.
    2. If the year is evenly divisible by 100, go to step 3. Otherwise, go to step 4.
    3. If the year is evenly divisible by 400, go to step 4. Otherwise, go to step 5.
    4. The year is a leap year (it has 366 days).
    5. The year is not a leap year (it has 365 days).
*/
// 0 is false, 1 is true
int findLeapYear(int year) {
    // #1
    if (year % 4 == 0) {
        // #2
        if (year % 100 == 0) {
            // #3
            if (year % 400 == 0) {
                // #4
                return 1;
            }
        } else {
            // #4
            return 1;
        }
    }
    return 0;
}

int main() {
    time_t seconds=time(NULL);
    struct tm* current_time=localtime(&seconds); 

    int year = current_time->tm_year + 1900;
    printf("This year is:%d\nThis year is %sleap year", year, findLeapYear(year) == 0 ? "not a " : "");
    printf("\n----------------------------------------------------------------------\n");
    
    // find leap year
    int count = 0;
    do {
        if (findLeapYear(year) == 1) {
            count++;
            printf("%d => %d\n", count, year);
        }
        year++;
    } while(count < 20);
    
    return 0;
}