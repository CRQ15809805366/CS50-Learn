#include <stdio.h>

int main()
{
    // ====变量部分=====
    int n;      // n为猴子个数
    int m;      // 报数到m退出
    int number; // 剩余猴子个数
    int count;  // 报数序号
    int pos;    // 储存数组下表

    // scanf返回读取到的数字个数
    // 如果scanf没有成功(如输入错误), 它会返回-1,
    // ~为位取反运算符
    // ~(-1)会变成0, while循环就会停止
    // 但实际上会一直等待用户输入
    while (~scanf("%d %d", &n, &m))
    {
        // 终止标志则退出循环
        if (n == 0 || n == 0)
            break;

        number = n; // 没有猴子被淘汰
        // 数组元素为1~n表示猴子未被淘汰
        // 数组元素等于0表示猴子被淘汰
        // 数组元素等于-1表示无效数据
        int monkey[301] = {-1};
        for (int i = 0; i < n; i++)
        {
            monkey[i] = i + 1;
        }
        pos = 0; // 数组下标为0
    }

    return 0;
}