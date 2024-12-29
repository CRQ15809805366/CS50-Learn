#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *prev;
    struct node *next;
} node;

bool del_node(node **head, int tar_val);
void destroy(node *head);

int main(int argc, char *argv[])
{
    // Memory for numbers
    node *list = NULL; // 链表入口

    // For each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument to int
        int number = atoi(argv[i]);

        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
            return 1;
        n->number = number; // 填入数字
        n->prev = NULL;
        n->next = NULL; // 设置空指针

        // If list is empty // 空首位
        if (list == NULL)
        {
            list = n;
        }

        // If number belongs at beginning of list // 非空首位(与第一个节点比较)
        else if (n->number < list->number)
        {
            n->next = list; // 连接下一节点
            list->prev = n; // 下一节点连接自身
            list = n;       // 更新链表入口
        }

        // If number belongs later in list // 非首位
        else
        {
            // Iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                if (ptr->next == NULL)
                {
                    // Append node
                    ptr->next = n;
                    break;
                }

                // If in middle of list // 从第二个节点开始比较
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next; // 自身连接下一节点
                    n->prev = ptr;       // 自身连接上一节点
                    ptr->next = n;       // 上一节点连接自身
                    ptr->next->prev = n; // 下一节点连接自身
                    break;
                }
            }
        }
    }

    // 获取欲删除节点
    int pdel = 0;
    printf("Delete: ");
    scanf("%i", &pdel);

    // 删除某个节点
    node **head = &list;
    if (!del_node(head, pdel))
    {
        printf("Element not found.\n");
        return 1;
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    destroy(list);
}

void destroy(node *head)
{
    // base case
    if (head == NULL)
        return;

    // recursion case
    destroy(head->next);
    free(head);
}

bool del_node(node **head, int tar_val)
{
    node *ptr = *head;

    // 欲删除的是首位节点
    if (ptr->number == tar_val && ptr != NULL)
    {
        *head = ptr->next;  // 入口更改为第二位节点
        (*head)->prev = NULL; // 新首位节点向前指向空
        free(ptr);          // 释放首位节点
        return true;
    }

    // 遍历链表并更新指针指向
    while (ptr != NULL && ptr->number != tar_val)
    {
        ptr = ptr->next;
    }

    // 未找到目标节点
    if (ptr == NULL)
    {
        printf("Element not found.\n");
        return false;
    }

    // 删除节点
    ptr->prev->next = ptr->next; // 上一位节点指向下一位节点
    ptr->next->prev = ptr->prev; // 下一位节点指向上一位节点
    free(ptr);
    return true;
}
