// 四舍五入
#include <stdio.h>
#include <math.h>

// +0.5, 保留整数部分
double inte(double);

int main(void) {
    printf("%g", inte(1.5));
    return 0;
}

/* The ceil() function rounds upwards to its nearest integer,
and the floor() method rounds a number downwards to its nearest integer,
and returns the results */
double inte(double x) {
    x = floor(x + 0.5);
}
