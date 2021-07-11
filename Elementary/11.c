#include <stdio.h>
#include <math.h>
#include <ctype.h>

struct Summary {
    double normal;
    double pluse;
    double subtract;
    double product;
    double divide;
};

struct SummaryCheck {
    int normal;
    int pluse;
    int subtract;
    int product;
    int divide;
};


// return in 100K unit
double calculate(double k) {
    double result = ((pow(-1, (k+1))) / (2 * (k-1)))*100000;
    return isfinite(result) ? result : 0;  // if receive infinity, returns 0
}

int main() {
    printf("Expression: ((-1)^{k+1})/(2 * k-1)\n");

    int maxValue = 1000000; // 1M
    struct Summary Sum;
    Sum.normal = 0;
    Sum.pluse = 0;
    Sum.subtract = 0;
    Sum.product = 0;
    Sum.divide = 0;

    // 0 is false, 1 is true
    struct SummaryCheck SumCheck;
    SumCheck.normal = 1; // alway true
    SumCheck.pluse = 1;
    SumCheck.subtract = 1; // alway true
    SumCheck.product = 1;
    SumCheck.divide = 1; // alway true


    double sum = 0;

    // ((a + b + c + ...) * x)/x = (ax + bx + cx + ...)/x
    // 2(K-1) is not zero; k != 1
    int k;
    for(k = 2; k <= maxValue; k++) {
        // Normal
        Sum.normal += calculate(k);

        // k/4
        Sum.divide += calculate((double)k/4);
        // k - 4
        Sum.subtract += calculate((double)k - 4);

        // k * 4
        if (SumCheck.product == 1) {
            double kM = (double)k*4;

            if (kM > maxValue) {
                SumCheck.product = 0;
                printf("STOP multiply\n");
            } else {
                Sum.product += calculate((double)k*4);
            }
        }

        // k + 4
        if (SumCheck.pluse == 1) {
            double kP = (double)k+4;
            if (kP > maxValue) {
                SumCheck.pluse = 0;
                printf("STOP pluse\n");
            } else {
                Sum.pluse += calculate(kP);
            }
        }
    }
    printf("Sum of normal k:%f\n", Sum.normal / 100000);
    printf("Sum of k for subtracted by 4:%f\n", Sum.subtract / 100000);
    printf("Sum of k for pulsed by 4:%f\n", Sum.pluse / 100000);
    printf("Sum of k for divided by 4:%f\n", Sum.divide / 100000);
    printf("Sum of k for multiplied by 4:%f\n", Sum.product / 100000);
    return 0;
}