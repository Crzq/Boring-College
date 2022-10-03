#include <stdio.h>
#include <windows.h>

int Addition(double, double);

int Subtraction(double, double);

int Multiplication(double, double);

int Division(double, double);


int main() {
    // num1+num2
    double num1, num2;
    char operator;

    // 这里用 printf 有问题
    LOOP:
    printf("请输入算式：\n");
    scanf("%lf%c%lf", &num1, &operator, &num2);

    switch (operator) { // 只能用于整数
        case '+':
            Addition(num1, num2);
            break;
        case '-':
            Subtraction(num1, num2);
            break;
        case '*':
            Multiplication(num1, num2);
            break;
        case '/':
            if (num2 != 0) {
                Division(num1, num2);
            } else {
                printf("分母不能为 0 ,请重新输入算式：\n");
                goto LOOP;
            }
            break;
        default:
            printf("请输入正确的运算符号\n");
            goto LOOP;
    }


    // 做一个循环，这是 按任意键继续 goto
    printf("按 Enter 键以继续计算，或按 其他 键退出 ...\n");
    char lo;
    getchar(); // 之前 lo 始终为 10 说明有个回车，但我真的找不到是哪个，要用getchar()吸收掉这个回车
    scanf("%c", &lo);

    // printf("lo = %d\n", lo);
    if (lo == '\n') { // 这里用 lo == '\10' 不行
        goto LOOP;
    } else {
        printf("bye");
    }
    // goto LOOP;

    return 0;
}

int Addition(double a, double b) {
    printf("%g\n", a + b);
    return 0;
}

int Subtraction(double a, double b) {
    printf("%g\n", a - b);
    return 0;
}

int Multiplication(double a, double b) {
    printf("%g\n", a * b);
    return 0;
} // 需额外判断分母不为0

int Division(double a, double b) {
    printf("%g\n", a / b);
    return 0;
}
