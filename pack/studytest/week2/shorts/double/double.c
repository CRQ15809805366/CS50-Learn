#include <cs50.h>
#include <stdio.h>

void create_array(int size, int array[]);
void print_array(int size, int array[]);

int main(void)
{
    // 输入数组大小
    const int N = get_int("Array size: ");

    // 创建数组
    int sequence[N];

    // 填入这个数组
    create_array(N, sequence);

    // 打印这个数组
    print_array(N, sequence);
}

void create_array(int size, int array[])
{
    for (int i = 0, number = 1; i < size; i++)
    {
        array[i] = number;
        number *= 2;
    } // 输入后直接修改,无需输出
}

void print_array(int size, int array[])
{
    for (int j = 0; j < size; j++)
    {
        printf("%i\n", array[j]);
    }
}
