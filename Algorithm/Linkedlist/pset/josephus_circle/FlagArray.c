#include <stdio.h>

int main()
{
    // ====变量部分=====
    int n;           // n为猴子个数
    int m;           // 报数到m退出
    int number;      // 剩余猴子个数
    int count;       // 报数序号
    int pos;         // 储存数组下标
    int answer[100]; // 储存答案
    int index = 0;   // 答案下标初始化为0

    // scanf返回读取到的数字个数
    // 如果scanf没有成功(如输入错误), 它会返回-1,
    // ~为位取反运算符
    // ~(-1)会变成0, while循环就会停止
    // 但实际上不会输入错误, 因此会一直等待用户输入
    while (~scanf("%d %d", &n, &m))
    {
        // 若遇终止标志则退出循环
        if (n == 0 || n == 0)
            break;

        // 数组元素为1~n表示猴子未被淘汰
        // 数组元素等于0表示猴子被淘汰
        // 数组元素等于-1表示无效数据
        int monkey[301] = {-1};
        for (int i = 0; i < n; i++)
        {
            monkey[i] = i + 1;
        }

        pos = 0;           // 数组下标为0
        count = 1;         // 从1开始报数
        number = n;        // 没有猴子被淘汰
        while (number > 1) // 剩余猴子大于1, 继续进行淘汰
        {
            if (monkey[pos] != 0) // 该猴子未被淘汰
            {
                if (count < m) // 报数未达到目标值
                {
                    pos = (pos + 1) % n;
                    /*
                     * 本步骤是实现循环数组的关键
                     * 当pos == n - 1时(最后一位), pos + 1 = n
                     * n % n = 0, 即回到首位
                     * 由此, 可成功构成循环数组
                     */
                    count++; // 报数值加1
                }
                else // 报数达到目标值
                {
                    monkey[pos] = 0;     // 淘汰猴子
                    number--;            // 剩余猴子数减1
                    pos = (pos + 1) % n; // 从下一位猴子
                    count = 0;           // 重新从零开始报数
                }
            }
            else // 该猴子已被淘汰
                pos = (pos + 1) % n; // 转到下一个猴子
        }

        for (int i = 0; i < n; i++)
        {
            if (monkey[i] > 0)
            {
                answer[index++] = monkey[i];
            }
        }
    }

    for (int i = 0; i < index; i++)
    {
        printf("%d\n", answer[i]);
    }

    return 0;
}