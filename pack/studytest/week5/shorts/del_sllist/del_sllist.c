#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int number;
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
        n->next = NULL;     // 设置空指针

        // If list is empty // 空首位
        if (list == NULL)
        {
            list = n;
        }

        // If number belongs at beginning of list // 非空首位(与第一个节点比较)
        else if (n->number < list->number)
        {
            n->next = list;
            list = n;
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
                    n->next = ptr->next;
                    ptr->next = n;
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
    if(!del_node(head, pdel))
        return 1;

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    destroy(list);
}

bool del_node(node **head, int tar_val)
{
    node *cur = *head;
    node *pre = NULL;

    // 欲删除的是首位节点
    if (cur->number == tar_val && cur != NULL)
    {
        *head = cur->next; // 入口更改为第二位节点
        free(cur); // 释放首位节点
        return true;
    }

    // 遍历链表并更新指针指向
    while (cur != NULL && cur->number != tar_val)
    {
        pre = cur;
        cur = cur->next;
    }

    // 未找到目标节点
    if (cur == NULL)
    {
        printf("Element not found.\n");
        return false;
    }

    // 删除节点
    pre->next = cur->next;
    free(cur);
    return true;
}

void destroy(node* head)
{
    // base case
    if (head == NULL)
        return;

    // recursion case
    destroy(head->next);
    free(head);
}
