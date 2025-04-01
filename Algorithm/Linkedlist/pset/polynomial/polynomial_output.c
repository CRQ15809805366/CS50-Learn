#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_TERMS 100

bool is_first;         // 是否是首项
int show_sign;         // 是否输出符号(0不输出, -1输出-, 1输出+)
bool show_coefficient; // 是否输出系数
bool show_x;           // 是否输出x
bool show_exponent;    // 是否输出指数

void print_term(int coefficient, int exponent, int show_sign, bool show_coefficient, bool show_x, bool show_exponent)
{
    // 打印符号
    if (show_sign == -1)
        printf("-");
    else if (show_sign == 1)
        printf("+");
    // 打印系数
    if (show_coefficient)
        printf("%d", coefficient);
    // 打印x
    if (show_x)
        printf("x");
    // 打印指数
    if (show_exponent)
        printf("^%d", exponent);
}

int main()
{
    // 传入最高次数与各项系数
    int highest_exponent;        // 存储最高次数
    int coefficients[MAX_TERMS]; // 存储各项系数
    scanf("%d", &highest_exponent);
    for (int i = 0; i < highest_exponent + 1; i++)
    {
        scanf("%d", coefficients + i);
    }

    is_first = true; // 准备处理首项
    // 处理0次项到最高次项
    for (int i = 0; i <= highest_exponent; i++)
    {
        // =====处理符号=====
        if (is_first) // 是首项
        {
            if (coefficients[i] > 0) // 首项系数为正
            {
                show_sign = 0;
                is_first = false; // 之后的项不再是首项
            }
            else if (coefficients[i] < 0) // 首项系数为负
            {
                show_sign = -1;
                is_first = false;
            }
            else // 首项系数为0
            {
                show_sign = 0;
                is_first = true; // 下一项视作首项
            }
        }
        else // 非首项
        {
            if (coefficients[i] > 0) // 系数为正
                show_sign = 1;
            else if (coefficients[i] < 0) // 系数为负
                show_sign = -1;
            else // 系数为0
                show_sign = 0;
        }

        // =====处理系数=====
        if (coefficients[i] == 0) // 系数为0
            show_coefficient = false;
        else if (abs(coefficients[i]) == 1) // 系数为1
            show_coefficient = (highest_exponent - i == 0); // 仅在常数项时输出
        else
            show_coefficient = true; // 其他情况正常输出

        // =====处理x=====
        if (highest_exponent - i == 0) // 指数为0
            show_x = false;            // 无需输出x
        else
            show_x = true;

        // =====处理指数=====
        if (highest_exponent - i == 0 || highest_exponent - i == 1) // 指数为0或1
            show_exponent = false;
        else
            show_exponent = true;

        // =====处理特殊情况=====
        if (coefficients[i] == 0) // 系数为0时, 输出为空
            show_coefficient = show_exponent = show_sign = show_x = false;

        // 输出这一项
        // 传入系数的绝对值, 因为符号已由show_sign控制
        print_term(abs(coefficients[i]), highest_exponent - i, show_sign, show_coefficient, show_x, show_exponent);
    }
    printf("\n");

    return 0;
}