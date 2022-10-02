#include <stdio.h>

int main(void) {
    int a = 1;
    LOOP: printf("hello\n");
    printf("world\n");
    if (a > 0) {
        --a;
        goto LOOP;
    }
    return 0;
}
