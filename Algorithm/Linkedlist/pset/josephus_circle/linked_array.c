#include <stdio.h>

int main()
{
    // ====变量部分=====
    int n;           // n为猴子个数
    int m;           // 报数到m退出
    int count;       // 报数序号
    int pos;         // 储存当前数组下标
    int prior;       // 储存当前数组下标的前一个下标
    int answer[100]; // 储存答案
    int index = 0;   // 答案下标初始化为0

    while (~scanf("%d %d", &n, &m))
    {
        if (n == 0 || n == 0)
            break;

        // 数组元素等于-1表示被淘汰的猴子
        int monkey[301] = {0};
        for (int i = 0; i < n - 1; i++)
        {
            // 前n - 1个猴子
            // 数组下标代表猴子编号
            // 数组内容代表下一个猴子的编号
            monkey[i] = i + 1;
        }
        monkey[n - 1] = 0;
        // 最后一个猴子的下一个猴子是第一个猴子
        // 则构成循环链表

        pos = 0;       // 当前指针指向头结点
        prior = n - 1; // 前驱指针指向尾结点
        count = 1;     // 从1开始报数

        // pos, prior总是一前一后, 若重合则说明仅剩一个猴子(猴王)
        while (pos != prior) 
        {
            if (count != m) // 报数未到达目标值
            {
                prior = pos;       // prior = pos;
                pos = monkey[pos]; // pos = pos->next;
                count++;           // 报数加1
            }
            else // 报数达到目标值
            {
                monkey[prior] = monkey[pos]; // prior->next = pos->next;
                monkey[pos] = -1;            // free(pos);
                pos = monkey[prior];         // pos = prior->next;
                count = 1; // 报数重新从1开始
            }
        }

        answer[index++] = pos + 1; // pos是数组下标, 从0开始; 答案为猴子序号, 从1开始
    }

    for (int i = 0; i < index; i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}