#ifndef SEQLIST_H
#define SEQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100 // 顺序表最大容量

typedef struct
{
    int data[MAXSIZE]; // 存储数据元素
    int length;        // 当前长度
} SeqList;

// 初始化顺序表
void InitList(SeqList *L)
{
    L->length = 0;
}

// 判断顺序表是否为空
bool ListEmpty(SeqList *L)
{
    return L->length == 0;
}

// 获取顺序表长度
int ListLength(SeqList *L)
{
    return L->length;
}

// 在第i个位置插入元素x
bool ListInsert(SeqList *L, int i, int x)
{
    if (L->length >= MAXSIZE)
    {
        printf("顺序表已满，无法插入\n");
        return false;
    }
    if (i < 1 || i > L->length + 1)
    {
        printf("插入位置不合法\n");
        return false;
    }

    for (int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = x;
    L->length++;
    return true;
}

// 删除第i个元素
bool ListDelete(SeqList *L, int i, int *e)
{
    if (ListEmpty(L))
    {
        printf("顺序表为空，无法删除\n");
        return false;
    }
    if (i < 1 || i > L->length)
    {
        printf("删除位置不合法\n");
        return false;
    }

    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++)
    {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return true;
}

// 在有序表中插入元素x，保持有序性
bool ListInsertOrder(SeqList *L, int x)
{
    if (L->length >= MAXSIZE)
    {
        printf("顺序表已满，无法插入\n");
        return false;
    }

    int i = 0;
    while (i < L->length && L->data[i] < x)
    {
        i++;
    }

    for (int j = L->length; j > i; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[i] = x;
    L->length++;
    return true;
}

// 分离奇偶元素
void SplitList(SeqList *L, SeqList *OddList, SeqList *EvenList)
{
    InitList(OddList);
    InitList(EvenList);

    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] % 2 == 1)
        {
            OddList->data[OddList->length++] = L->data[i];
        }
        else
        {
            EvenList->data[EvenList->length++] = L->data[i];
        }
    }
}

// 求两个有序表的公共元素
void CommonElements(SeqList *L1, SeqList *L2, SeqList *L3)
{
    InitList(L3);

    int i = 0, j = 0;
    while (i < L1->length && j < L2->length)
    {
        if (L1->data[i] < L2->data[j])
        {
            i++;
        }
        else if (L1->data[i] > L2->data[j])
        {
            j++;
        }
        else
        {
            L3->data[L3->length++] = L1->data[i];
            i++;
            j++;
        }
    }
}

// 删除重复元素并统计移动次数
int RemoveDuplicates(SeqList *L)
{
    if (ListEmpty(L))
    {
        return 0;
    }

    int moveCount = 0;
    int i = 0; // 慢指针
    for (int j = 1; j < L->length; j++)
    { // 快指针
        if (L->data[j] != L->data[i])
        {
            i++;
            if (i != j)
            {
                L->data[i] = L->data[j];
                moveCount++;
            }
        }
    }
    L->length = i + 1;
    return moveCount;
}

// 打印顺序表
void PrintList(SeqList *L)
{
    if (ListEmpty(L))
    {
        printf("顺序表为空\n");
        return;
    }

    printf("顺序表元素: ");
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

#endif