#include <stdio.h>

int main(void) {
    char a, b;
    printf("请输入 a 的值：\n");
    scanf("%c", &a);

    // getchar();

    printf("请输入 b 的值：\n");
    scanf("%c", &b);

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}
