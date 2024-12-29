#include <cs50.h>
#include <stdio.h>

int calculate(int value, int steps);

int main(void)
{
    int value = get_int("Input: ");
    int steps = get_int("Iteration steps: ");

    int product = calculate(value, steps);
    printf("Product:%i\n", product);
}

// 人为递归函数算法(双参数法)
int calculate(int value, int steps)
{
    if (steps == 0)
        return value; // 强制返回单参数

    if (value % 2 == 0)
        return calculate(value / 2, steps - 1);

    else
        return calculate(value * 3 + 1, steps - 1);
}
