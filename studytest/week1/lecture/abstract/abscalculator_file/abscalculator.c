#include <cs50.h>
#include <stdio.h>

double divide(double a, double b); // protype

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("x / y = %.5f\n", divide((double)x, (double)y));
    // percent dot five 即为保留至小数点后第五位
    // 复合函数,直接利用返回值
    // 调用函数时将 x 与 y 从整数类型转换为双精度浮点数并进行输入
}

double divide(double a, double b) // 输入两个双精度浮点数并赋值为 a , b
{
    return a / b; // 输出 a / b 作为返回值
}
