#define _GNU_SOURCE
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_COUNT 26
#define NUMBER_LENGTH 17
#define NAME_LENGTH_MAX 100

typedef struct node
{
    char *name;
    char *number;
    struct node *prev;
    struct node *next;
} node;

node *table[ALPHABET_COUNT] = {NULL};

unsigned int hash(char *str);
void create_node(char *name, char *number);
bool del_node(node **head, char *tar_val);
void destroy(node *head);

int main(void)
{
    int num_people;

    // 输入人数
    printf("Number of people: ");
    scanf("%d", &num_people);

    // 清理输入缓冲区
    while (getchar() != '\n')
        ; // 清除残留的换行符

    for (int i = 0; i < num_people; i++)
    {
        // 获取名字
        printf("Name: ");
        char *name = malloc(NAME_LENGTH_MAX); // 假设名字最大长度为99字符
        if (fgets(name, NAME_LENGTH_MAX, stdin) == NULL)
        {
            fprintf(stderr, "Error reading name\n");
            free(name);
            return 1;
        }
        // 移除输入中的换行符
        name[strcspn(name, "\n")] = '\0';

        // 获取号码
        printf("Number: ");
        char *number = malloc(NUMBER_LENGTH + 1); // 为号码加终止符
        if (fgets(number, NUMBER_LENGTH + 1, stdin) == NULL)
        {
            fprintf(stderr, "Error reading number\n");
            free(name);
            free(number);
            return 1;
        }
        // 移除输入中的换行符
        number[strcspn(number, "\n")] = '\0';

        // 创建节点
        create_node(name, number);

        // 释放内存
        free(name);
        free(number);
    }

    // 删除节点
    char *pdel = get_string("Delete: ");
    unsigned int hash_number = hash(pdel);
    node **head = &(table[hash_number]);
    if (!del_node(head, pdel))
    {
        printf("Element not found.\n");
        return 1;
    }

    // 打印与删除节点哈希值相同的所有节点
    for (node *ptr = *head; ptr != NULL; ptr = ptr->next)
    {
        printf("Name: %s Phonenumber: %s\n", ptr->name, ptr->number);
    }

    // Free memory
    for (int j = 0; j < ALPHABET_COUNT; j++)
    {
        destroy(table[j]);
    }
}

unsigned int hash(char *str)
{
    return (toupper(str[0]) - 'A');
}

// Add this helper function before create_node
char* string_duplicate(const char* str) {
    size_t len = strlen(str) + 1;  // +1 for null terminator
    char* new_str = malloc(len);
    if (new_str) {
        memcpy(new_str, str, len);
    }
    return new_str;
}

void create_node(char *name, char *number)
{
    // 创建临时节点
    node *n = malloc(sizeof(node));
    if (n == NULL)
        return;

    // Allocate memory for strings and copy them
    n->name = string_duplicate(name);
    n->number = string_duplicate(number);
    if (n->name == NULL || n->number == NULL)
    {
        free(n->name);
        free(n->number);
        free(n);
        return;
    }

    n->prev = NULL;
    n->next = NULL;

    unsigned int hash_number = hash(name);

    // 链表为空
    if (table[hash_number] == NULL)
    {
        table[hash_number] = n;
        return;
    }

    // 链表非空
    for (node *ptr = table[hash_number]; ptr != NULL; ptr = ptr->next)
    {
        // If at end of list
        if (ptr->next == NULL)
        {
            // Append node
            ptr->next = n; // 末位节点指向新节点
            n->prev = ptr; // 新节点指向末位节点
            break;
        }
    }
}

bool del_node(node **head, char *tar_val)
{
    node *ptr = *head;

    // 欲删除的是首位节点
    if (ptr != NULL && strcmp(ptr->name, tar_val) == 0)  // Changed to compare names
    {
        *head = ptr->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(ptr->name);    // Free strings before freeing node
        free(ptr->number);
        free(ptr);
        return true;
    }

    // 遍历链表并更新指针指向
    while (ptr != NULL && strcmp(ptr->name, tar_val) != 0)  // Changed to compare names
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
    if (ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;
    free(ptr->name);    // Free strings before freeing node
    free(ptr->number);
    free(ptr);
    return true;
}

void destroy(node *head)
{
    // base case
    if (head == NULL)
        return;

    // recursion case
    destroy(head->next);
    free(head->name);    // Free strings before freeing node
    free(head->number);
    free(head);
}
