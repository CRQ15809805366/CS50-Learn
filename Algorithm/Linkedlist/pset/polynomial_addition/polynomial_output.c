#include <stdio.h>
#include <stdbool.h>

int show_sign;         // 是否输出符号(0不输出, -1输出-, 1输出+)
bool show_coefficient; // 是否输出系数
bool show_x;           // 是否输出x
bool show_exponent;    // 是否输出指数
bool is_first;         // 是否是首项

void print_polynomial_format(bool show_coefficient, bool show_x, bool show_exponent, bool is_first)
{
    
}

int main()
{
    int highest_degree;    // 存储最高次数
    int coefficients[100]; // 存储各项系数
    scanf("%d", &highest_degree);
    for (int i = 0; i < highest_degree + 1; i++)
    {
        scanf("%d", coefficients + i);
    }

    return 0;
}