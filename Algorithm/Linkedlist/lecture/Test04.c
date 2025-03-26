#include <stdio.h>
#include <stdbool.h>

typedef struct node1
{
    int data;
    struct node1 *next;
} Node1, *Link1;

// 单链表计数
int length(Link1 head)
{
    Link1 p = head->next;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

// 单链表查找
bool queryNode(Link1 head, int x)
{
    Link1 p = head->next;
    while (p != NULL)
    {
        if (p->data == x)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

// 单链表插入
bool insertNode(Link1 head, int i, int x)
{
    // 使得p指向头节点(空表也有头节点, 因此允许插入空表)
    Link1 p = head;
    int count = 0;

    // 使得p指向插入位置的前一位
    // 排除了无效链表的可能
    while (p != NULL && count < i - 1)
    {
        p = p->next;
        count++;
    }

    // 如果链表过短, 到达链表尾部自动退出, 但未到达欲插入位置
    if (p == NULL)
    {
        return false;
    }
    else
    {
        Link1 node = (Link1)malloc(sizeof(Node1));
        node->data = x;
        node->next = p->next;
        p->next = node;
        return true;
    }
}

// 单链表创建(头插法)
Link1 newList1(int a[], int n)
{
    Link1 head = (Link1)malloc(sizeof(Node1));
    head->next = NULL;

    for (int i = 0; i < n; i++)
    {
        Link1 node = (Link1)malloc(sizeof(Node1));
        node->data = a[i];
        node->next = head->next;
        head->next = node;
    }

    return head;
}

// 单链表创建(尾插法)
Link1 newList2(int a[], int n)
{
    // 创建头结点
    Link1 head = (Link1)malloc(sizeof(Node1));
    head->next = NULL;
    // 创建尾指针(空表时头尾指针指向同一处)
    Link1 rear = head;

    for (int i = 0; i < n; i++)
    {
        Link1 node = (Link1)malloc(sizeof(Node1));
        node->data = a[i];
        node->next = NULL;
        rear->next = node;
        rear = node;
    }

    return head;
}

// 单链表结点删除
bool deleteNode(Link1 head, int x)
{
    // 排除空表
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    Link1 q = head;
    Link1 p = head->next;

    while (p != NULL)
    {
        if (p->data == x)
        {
            q->next = p->next;
            free(p);
            return true;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }

    return false;
}

// 单链表释放
void clearLink(Link1 head)
{
    Link1 q = head;
    while (head != NULL)
    {
        head = head->next;
        free(q);
        q = head;
    }
}

/*
 * 循环链表
 * 特点:
 * rear->next = head;
 * 遍历结束条件
 * p == head;
 */

// 双向链表
typedef struct node2
{
    int data;
    struct node2 *prior;
    struct node2 *next;
} Node2, *Link2;

int main()
{
    return 0;
}