#include <cs50.h>
#include <stdio.h>

const int N = 3; // 命名全局变量常用大写

float average(int length, int array[]); // int [] 仅仅是一个格式

int main(void)
{
    // Scores
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Scores: ");
    }

    // Print average
    printf("Average: %.2f\n", average(N, scores));
}

float average(int length, int array[])
{
    // 计算数组和固定方法
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }

    return sum / (float) length;
}
