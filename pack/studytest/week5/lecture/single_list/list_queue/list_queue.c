// Implements a list of numbers using a linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node; 

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

        // If list is empty
        if (list == NULL)
            // This node is the whole list
            list = n;

        // If list has numbers already
        else
        {
            // Iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                if (ptr->next == NULL) // ptr指向末位节点
                {
                    // Append node
                    ptr->next = n; // 末位节点指向新节点
                    break;
                }
            }
        }
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    node *ptr = list;   // 指针指向首位
    while (ptr != NULL) // 指针从首位至末位,空地址停止
    {
        node *next = ptr->next; // 储存本位的下一位地址
        free(ptr);              // 删除本位
        ptr = next;             // 指向下一位
    }
}
