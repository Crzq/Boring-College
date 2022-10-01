#include <stdio.h>
#include <windows.h>

int Addition(double, double);
int Subtraction(double, double);
int Multiplication(double, double);
int Division(double, double);


int main()
{
    // num1+num2
    double num1, num2;
    char operator;
    printf("请输入算式：\n");
    // 这里用 printf 有问题
    scanf("%lf%c%lf", &num1, &operator, &num2);
//    printf("%c\n", operator);
//    printf("%zd\n", sizeof(operator));
//    printf("%zd\n", sizeof(num1));

    switch (operator) { // 只能用于整数
        case '+': Addition(num1, num2); break;
        case '-': Subtraction(num1, num2); break;
        case '*': Multiplication(num1, num2); break;
        case '/':
            if (num2 != 0) {
                Division(num1, num2);
            } else {
                printf("分母不能为0");
            }
            break;
        default: printf("请输入正确的运算符号");
    }

    // 做一个循环，这是 按任意键继续 goto
    system("pause");

    return 0;
}

int Addition(double a, double b) { printf("%g\n", a + b); return 0; }
int Subtraction(double a, double b) { printf("%g\n", a - b); return 0; }
int Multiplication(double a, double b) { printf("%g\n", a * b); return 0; } // 需额外判断分母不为0
int Division(double a, double b) { printf("%g\n", a / b); return 0; }
