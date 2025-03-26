#include <cs50.h>
#include <stdio.h>

void meow(int n); // prototype,注意分号

int main(void)
{
    meow(5); // 输入 5 作为 n , 无输出//实现在此处调节次数
}

void meow(int n) // Abstract 自定义函数:输入整数作为 n , 无输出
{
    for (int i = 0; i < n; i++) // 利用n
    {
        printf("meow\n");
    }
}
