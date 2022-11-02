#include <stdio.h>

int main(void) {
    float a, b;
    a = 123456.789e5;
    b = a + 20;
    printf("a = %f, b = %f\n", a, b);
    printf("a = %e, b = %e\n", a, b);
    getchar();
    return 0;
}
