#include "seqList.h"
#include <stdio.h>

void testInsert()
{
    printf("\n=== 测试插入操作 ===\n");

    // 第一组数据
    SeqList L1;
    InitList(&L1);
    for (int i = 1; i <= 10; i++)
    {
        ListInsert(&L1, i, i * 10);
    }
    printf("初始顺序表: ");
    PrintList(&L1);

    printf("插入100到位置5: ");
    ListInsert(&L1, 5, 100);
    PrintList(&L1);

    printf("插入100到位置n(n=%d): ", L1.length);
    ListInsert(&L1, L1.length, 100);
    PrintList(&L1);

    printf("插入100到位置n+1(n=%d): ", L1.length);
    ListInsert(&L1, L1.length + 1, 100);
    PrintList(&L1);

    printf("插入100到位置0: ");
    ListInsert(&L1, 0, 100);

    printf("插入100到位置1: ");
    ListInsert(&L1, 1, 100);
    PrintList(&L1);

    printf("插入100到位置n+2(n=%d): ", L1.length);
    ListInsert(&L1, L1.length + 2, 100);

    // 第二组数据
    SeqList L2;
    InitList(&L2);
    printf("\n空表插入100到位置5: ");
    ListInsert(&L2, 5, 100);
    PrintList(&L2);
}

void testDelete()
{
    printf("\n=== 测试删除操作 ===\n");

    // 第一组数据
    SeqList L1;
    InitList(&L1);
    for (int i = 1; i <= 10; i++)
    {
        ListInsert(&L1, i, i * 10);
    }
    printf("初始顺序表: ");
    PrintList(&L1);

    int e;
    printf("删除位置5: ");
    if (ListDelete(&L1, 5, &e))
    {
        printf("删除的元素是%d, 删除后: ", e);
        PrintList(&L1);
    }

    printf("删除位置n(n=%d): ", L1.length);
    if (ListDelete(&L1, L1.length, &e))
    {
        printf("删除的元素是%d, 删除后: ", e);
        PrintList(&L1);
    }

    printf("删除位置1: ");
    if (ListDelete(&L1, 1, &e))
    {
        printf("删除的元素是%d, 删除后: ", e);
        PrintList(&L1);
    }

    printf("删除位置n+1(n=%d): ", L1.length);
    ListDelete(&L1, L1.length + 1, &e);

    printf("删除位置0: ");
    ListDelete(&L1, 0, &e);

    // 第二组数据
    SeqList L2;
    InitList(&L2);
    printf("\n空表删除位置5: ");
    ListDelete(&L2, 5, &e);
    PrintList(&L2);
}

void testInsertOrder()
{
    printf("\n=== 测试有序插入 ===\n");

    SeqList L;
    InitList(&L);
    int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for (int i = 0; i < 10; i++)
    {
        ListInsert(&L, i + 1, data[i]);
    }
    printf("初始有序表: ");
    PrintList(&L);

    printf("插入25: ");
    ListInsertOrder(&L, 25);
    PrintList(&L);

    printf("插入85: ");
    ListInsertOrder(&L, 85);
    PrintList(&L);

    printf("插入110: ");
    ListInsertOrder(&L, 110);
    PrintList(&L);

    printf("插入8: ");
    ListInsertOrder(&L, 8);
    PrintList(&L);
}

void testSplitList()
{
    printf("\n=== 测试分离奇偶元素 ===\n");

    // 第一组数据
    SeqList L1, Odd1, Even1;
    InitList(&L1);
    int data1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60};
    for (int i = 0; i < 15; i++)
    {
        ListInsert(&L1, i + 1, data1[i]);
    }
    printf("初始顺序表: ");
    PrintList(&L1);

    SplitList(&L1, &Odd1, &Even1);
    printf("奇数元素表: ");
    PrintList(&Odd1);
    printf("偶数元素表: ");
    PrintList(&Even1);

    // 第二组数据
    SeqList L2, Odd2, Even2;
    InitList(&L2);
    int data2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for (int i = 0; i < 10; i++)
    {
        ListInsert(&L2, i + 1, data2[i]);
    }
    printf("\n初始顺序表: ");
    PrintList(&L2);

    SplitList(&L2, &Odd2, &Even2);
    printf("奇数元素表: ");
    PrintList(&Odd2);
    printf("偶数元素表: ");
    PrintList(&Even2);
}

void testCommonElements()
{
    printf("\n=== 测试公共元素 ===\n");

    // 第一组数据
    SeqList L1_1, L1_2, L1_3;
    InitList(&L1_1);
    InitList(&L1_2);
    int data1_1[] = {1, 3, 6, 10, 15, 16, 17, 18, 19, 20};
    int data1_2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 18, 20, 30};
    for (int i = 0; i < 10; i++)
    {
        ListInsert(&L1_1, i + 1, data1_1[i]);
    }
    for (int i = 0; i < 13; i++)
    {
        ListInsert(&L1_2, i + 1, data1_2[i]);
    }
    printf("顺序表1: ");
    PrintList(&L1_1);
    printf("顺序表2: ");
    PrintList(&L1_2);

    CommonElements(&L1_1, &L1_2, &L1_3);
    printf("公共元素表: ");
    PrintList(&L1_3);

    // 第二组数据
    SeqList L2_1, L2_2, L2_3;
    InitList(&L2_1);
    InitList(&L2_2);
    int data2_1[] = {1, 3, 6, 10, 15, 16, 17, 18, 19, 20};
    int data2_2[] = {2, 4, 5, 7, 8, 9, 12, 22};
    for (int i = 0; i < 10; i++)
    {
        ListInsert(&L2_1, i + 1, data2_1[i]);
    }
    for (int i = 0; i < 8; i++)
    {
        ListInsert(&L2_2, i + 1, data2_2[i]);
    }
    printf("\n顺序表1: ");
    PrintList(&L2_1);
    printf("顺序表2: ");
    PrintList(&L2_2);

    CommonElements(&L2_1, &L2_2, &L2_3);
    printf("公共元素表: ");
    PrintList(&L2_3);

    // 第三组数据
    SeqList L3_1, L3_2, L3_3;
    InitList(&L3_1);
    InitList(&L3_2);
    int data3_2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++)
    {
        ListInsert(&L3_2, i + 1, data3_2[i]);
    }
    printf("\n顺序表1: ");
    PrintList(&L3_1);
    printf("顺序表2: ");
    PrintList(&L3_2);

    CommonElements(&L3_1, &L3_2, &L3_3);
    printf("公共元素表: ");
    PrintList(&L3_3);
}

void testRemoveDuplicates()
{
    printf("\n=== 测试删除重复元素 ===\n");

    // 第一组数据
    SeqList L1;
    InitList(&L1);
    int data1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9; i++)
    {
        ListInsert(&L1, i + 1, data1[i]);
    }
    printf("初始顺序表: ");
    PrintList(&L1);

    int moves1 = RemoveDuplicates(&L1);
    printf("删除重复后: ");
    PrintList(&L1);
    printf("移动次数: %d\n", moves1);

    // 第二组数据
    SeqList L2;
    InitList(&L2);
    int data2[] = {1, 1, 2, 2, 2, 3, 4, 5, 5, 5, 6, 6, 7, 7, 8, 8, 9};
    for (int i = 0; i < 17; i++)
    {
        ListInsert(&L2, i + 1, data2[i]);
    }
    printf("\n初始顺序表: ");
    PrintList(&L2);

    int moves2 = RemoveDuplicates(&L2);
    printf("删除重复后: ");
    PrintList(&L2);
    printf("移动次数: %d\n", moves2);

    // 第三组数据
    SeqList L3;
    InitList(&L3);
    int data3[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 8, 9, 9, 9, 9, 9};
    for (int i = 0; i < 15; i++)
    {
        ListInsert(&L3, i + 1, data3[i]);
    }
    printf("\n初始顺序表: ");
    PrintList(&L3);

    int moves3 = RemoveDuplicates(&L3);
    printf("删除重复后: ");
    PrintList(&L3);
    printf("移动次数: %d\n", moves3);
}

int main()
{
    testInsert();
    testDelete();
    testInsertOrder();
    testSplitList();
    testCommonElements();
    testRemoveDuplicates();
    return 0;
}