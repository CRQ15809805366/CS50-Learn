#include <cs50.h>
#include <stdio.h>

int get_size();
void print_bricks(int n);

int main()
{
    print_bricks(get_size()); // 复合函数,将get_size函数视作返回值,赋值为 n
}

// 获取尺寸
int get_size() // 自定义函数
{
    int m;
    do
    {
        m = get_int("Size: ");
    } while (m < 1); // 确保用户输入正确形式
    return m; // 返回值,即为这个函数的具体体现
}

// 打印砖块
void print_bricks(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("FUCK YOU ");
        }
        printf("\n");
    }
}

