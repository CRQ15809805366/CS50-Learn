#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化单链表
bool InitList(LinkList *L)
{
    *L = (LNode *)malloc(sizeof(LNode));
    if (*L == NULL)
        return false;
    (*L)->next = NULL;
    return true;
}

// 判断单链表是否为空
bool ListEmpty(LinkList L)
{
    return L->next == NULL;
}

// 头插法建立单链表
void CreateList_H(LinkList *L, int arr[], int n)
{
    InitList(L);
    for (int i = 0; i < n; i++)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = arr[i];
        s->next = (*L)->next;
        (*L)->next = s;
    }
}

// 尾插法建立单链表
void CreateList_T(LinkList *L, int arr[], int n)
{
    InitList(L);
    LNode *r = *L; // 尾指针
    for (int i = 0; i < n; i++)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = arr[i];
        s->next = NULL;
        r->next = s;
        r = s;
    }
}

// 打印单链表
void PrintList(LinkList L)
{
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 1. 分离奇偶元素
void SplitList(LinkList L, LinkList *OddList, LinkList *EvenList)
{
    InitList(OddList);
    InitList(EvenList);
    LNode *p = L->next;
    LNode *r1 = *OddList, *r2 = *EvenList;

    while (p != NULL)
    {
        if (p->data % 2 == 1)
        { // 奇数
            r1->next = p;
            r1 = p;
        }
        else
        { // 偶数
            r2->next = p;
            r2 = p;
        }
        p = p->next;
    }
    r1->next = NULL;
    r2->next = NULL;
}

// 2. 求两个有序链表的公共元素
void CommonElements(LinkList L1, LinkList L2, LinkList *L3)
{
    InitList(L3);
    LNode *p1 = L1->next, *p2 = L2->next;
    LNode *r = *L3;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p1 = p1->next;
        }
        else if (p1->data > p2->data)
        {
            p2 = p2->next;
        }
        else
        {
            LNode *s = (LNode *)malloc(sizeof(LNode));
            s->data = p1->data;
            s->next = NULL;
            r->next = s;
            r = s;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
}

// 3. 删除有序链表中的重复元素
void RemoveDuplicates(LinkList L)
{
    if (ListEmpty(L))
        return;

    LNode *p = L->next;
    while (p->next != NULL)
    {
        if (p->data == p->next->data)
        {
            LNode *q = p->next;
            p->next = q->next;
            free(q);
        }
        else
        {
            p = p->next;
        }
    }
}

// 4. 合并两个有序链表，不申请新结点
void MergeList(LinkList *L1, LinkList *L2)
{
    LNode *p1 = (*L1)->next, *p2 = (*L2)->next;
    LNode *r = *L1;
    r->next = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            r->next = p1;
            r = p1;
            p1 = p1->next;
        }
        else if (p1->data > p2->data)
        {
            r->next = p2;
            r = p2;
            p2 = p2->next;
        }
        else
        {
            r->next = p1;
            r = p1;
            p1 = p1->next;
            LNode *temp = p2;
            p2 = p2->next;
            free(temp);
        }
    }

    if (p1 != NULL)
        r->next = p1;
    if (p2 != NULL)
        r->next = p2;

    free(*L2); // 释放L2的头结点
    *L2 = NULL;
}

// 5. 查找链表中倒数第k个结点
int FindLastK(LinkList L, int k)
{
    LNode *fast = L->next, *slow = L->next;
    int count = 0;

    // fast指针先走k步
    while (fast != NULL && count < k)
    {
        fast = fast->next;
        count++;
    }

    if (count < k)
        return 0; // 链表长度不足k

    // fast和slow同时前进
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    printf("倒数第%d个结点的值为: %d\n", k, slow->data);
    return 1;
}

#endif