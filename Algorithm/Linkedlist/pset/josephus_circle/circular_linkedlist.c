#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *next;
} Node, *Link;

int main()
{
    // 变量部分:
    int n;           // n为猴子个数
    int m;           // 报数到m退出
    int count;       // 报数序号
    int answer[100]; // 保存每次答案
    int index = 0;   // 控制答案下标
    Link node;       // 新结点
    Link p, q;       // p指向当前处理结点, q指向前一个结点
    Link head, tail; // 头尾指针

    // 创建头结点
    head = (Link)malloc(sizeof(Node));
    head->data = -1;
    head->next = NULL;

    // 算法主体:
    // 每次用户输入两个数字并Enter录入时, 程序都自动计算并储存在答案数组中
    // 然后用户可以再输入两个数字, 会执行与之前相同的操作
    // 当用户输入任意一个0时即为终止信号, 不再录入并打印退出
    while (~scanf("%d %d", &n, &m))
    {
        // 终止信号: 退出while循环, 释放头结点
        if (n == 0 || m == 0)
        {
            free(head);
            break;
        }

        tail = head; // 初始化尾指针

        // 尾插法构建链表:
        for (int i = 0; i < n; i++)
        {
            // 创建新结点
            node = (Link)malloc(sizeof(Node));
            node->data = i + 1; // 猴子编号从一开始
            node->next = NULL;
            // 扩充循环链表
            tail->next = node;       // 将新猴子添加至链表尾部
            tail = node;             // 更新链表尾部
            tail->next = head->next; // 构成循环(连接首个有效结点)
        }

        // p, q一前一后进行初始化以便于删除结点
        p = head->next; // p指向第一个有效结点
        q = tail;       // q指向尾结点
        count = 1;      // 猴子从一号开始报数

        // 选出猴王:
        while (p != q) // p, q总是一前一后, 若重合则说明仅剩一个猴子(猴王)
        {
            if (count == m) // 报数到m则进行新一轮报数
            {
                q->next = p->next;
                free(p);     // 删除当前结点
                p = q->next; // 将p移动至下一有效结点(被淘汰的猴子的下一个猴子)
                count = 1;   // 从1重新开始报数
            }
            else // 报数未到达m
            {
                q = p;
                p = p->next;
                count++; // 报数加一
            }
        }
        head->next = p; // 删除最后两结点中第一个时, 会断开链表, 因此重新连接

        // 收尾工作:
        answer[index++] = p->data; // 将猴子序号写入答案数组
        // 初始化为空链表, 等待下一次录入n与m值
        head->next = NULL; // 先断开指针
        free(p);           // 再释放这块内存
    }

    // 结束部分:
    for (int i = 0; i < index; i++)
    {
        printf("%d\n", answer[i]);
    }
    free(head);
    return 0;
}
