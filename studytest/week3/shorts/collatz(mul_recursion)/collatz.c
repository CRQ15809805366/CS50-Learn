#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("n: ");
    }
    while (n < 1);

    int steps = collatz(n);

    printf("Need %i steps\n", steps);
}

// 本质:已知函数初始输入,表达式及最终迭代输出,求迭代次数
int collatz(int n) // n为函数初始输入
{
    // 此处为最终迭代输出(1)
    if (n == 1)
        return 0;
    // 反复放入临时输出进行迭代,直至最终输出,使用1记录步数
    if (n % 2 == 0)
        return 1 + collatz(n / 2); // 此处填写表达式,将函数的临时输出(n / 2)再次放入函数内
    else
        return 1 + collatz(3 * n + 1); // 此处填写表达式,将函数的临时输出(3 * n + 1)再次放入函数内

    // 直至输出为最终迭代输出(返回值加0),则开始计算返回值(每次迭代返回值加1),则通过返回值计算迭代次数并返回主函数
}
