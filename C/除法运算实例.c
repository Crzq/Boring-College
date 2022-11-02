#include <stdio.h>
#include <math.h>

int main(void) {
    printf("%f\n", pow(10, 0)); // 1
    printf("%f\n", pow(10, 1)); // 10
    printf("%f\n", pow(10, 1/2)); // 1
    // 除法运算，1/2直接得0，1.0/2或1/2.0才是0.5

    return 0;
}
