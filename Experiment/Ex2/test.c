#include "linkedList.h"
#include <stdio.h>

void testSplitList()
{
    printf("\n=== 测试分离奇偶元素 ===\n");

    // 第一组数据
    LinkList L1, Odd1, Even1;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60};
    CreateList_T(&L1, arr1, 15);
    printf("原链表L1: ");
    PrintList(L1);

    SplitList(L1, &Odd1, &Even1);
    printf("奇数链表Odd1: ");
    PrintList(Odd1);
    printf("偶数链表Even1: ");
    PrintList(Even1);

    // 第二组数据
    LinkList L2, Odd2, Even2;
    int arr2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    CreateList_T(&L2, arr2, 10);
    printf("\n原链表L2: ");
    PrintList(L2);

    SplitList(L2, &Odd2, &Even2);
    printf("奇数链表Odd2: ");
    PrintList(Odd2);
    printf("偶数链表Even2: ");
    PrintList(Even2);
}

void testCommonElements()
{
    printf("\n=== 测试公共元素 ===\n");

    // 第一组数据
    LinkList L1_1, L1_2, L1_3;
    int arr1_1[] = {1, 3, 6, 10, 15, 16, 17, 18, 19, 20};
    int arr1_2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 18, 20, 30};
    CreateList_T(&L1_1, arr1_1, 10);
    CreateList_T(&L1_2, arr1_2, 13);
    printf("链表L1: ");
    PrintList(L1_1);
    printf("链表L2: ");
    PrintList(L1_2);

    CommonElements(L1_1, L1_2, &L1_3);
    printf("公共元素链表L3: ");
    PrintList(L1_3);

    // 第二组数据
    LinkList L2_1, L2_2, L2_3;
    int arr2_1[] = {1, 3, 6, 10, 15, 16, 17, 18, 19, 20};
    int arr2_2[] = {2, 4, 5, 7, 8, 9, 12, 22};
    CreateList_T(&L2_1, arr2_1, 10);
    CreateList_T(&L2_2, arr2_2, 8);
    printf("\n链表L1: ");
    PrintList(L2_1);
    printf("链表L2: ");
    PrintList(L2_2);

    CommonElements(L2_1, L2_2, &L2_3);
    printf("公共元素链表L3: ");
    PrintList(L2_3);

    // 第三组数据
    LinkList L3_1, L3_2, L3_3;
    int arr3_2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    InitList(&L3_1);
    CreateList_T(&L3_2, arr3_2, 10);
    printf("\n链表L1: ");
    PrintList(L3_1);
    printf("链表L2: ");
    PrintList(L3_2);

    CommonElements(L3_1, L3_2, &L3_3);
    printf("公共元素链表L3: ");
    PrintList(L3_3);
}

void testRemoveDuplicates()
{
    printf("\n=== 测试删除重复元素 ===\n");

    // 第一组数据
    LinkList L1;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    CreateList_T(&L1, arr1, 9);
    printf("原链表L1: ");
    PrintList(L1);

    RemoveDuplicates(L1);
    printf("删除重复后L1: ");
    PrintList(L1);

    // 第二组数据
    LinkList L2;
    int arr2[] = {1, 1, 2, 2, 2, 3, 4, 5, 5, 5, 6, 6, 7, 7, 8, 8, 9};
    CreateList_T(&L2, arr2, 17);
    printf("\n原链表L2: ");
    PrintList(L2);

    RemoveDuplicates(L2);
    printf("删除重复后L2: ");
    PrintList(L2);

    // 第三组数据
    LinkList L3;
    int arr3[] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 8, 9, 9, 9, 9, 9};
    CreateList_T(&L3, arr3, 15);
    printf("\n原链表L3: ");
    PrintList(L3);

    RemoveDuplicates(L3);
    printf("删除重复后L3: ");
    PrintList(L3);
}

void testMergeList()
{
    printf("\n=== 测试合并有序链表 ===\n");

    // 第一组数据
    LinkList L1_1, L1_2;
    int arr1_1[] = {1, 3, 6, 10, 15, 16, 17, 18, 19, 20};
    int arr1_2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 18, 20, 30};
    CreateList_T(&L1_1, arr1_1, 10);
    CreateList_T(&L1_2, arr1_2, 13);
    printf("链表L1: ");
    PrintList(L1_1);
    printf("链表L2: ");
    PrintList(L1_2);

    MergeList(&L1_1, &L1_2);
    printf("合并后链表L1: ");
    PrintList(L1_1);

    // 第二组数据
    LinkList L2_1, L2_2;
    int arr2_1[] = {1, 3, 6, 10, 15, 16, 17, 18, 19, 20};
    int arr2_2[] = {2, 4, 5, 7, 8, 9, 12, 22};
    CreateList_T(&L2_1, arr2_1, 10);
    CreateList_T(&L2_2, arr2_2, 8);
    printf("\n链表L1: ");
    PrintList(L2_1);
    printf("链表L2: ");
    PrintList(L2_2);

    MergeList(&L2_1, &L2_2);
    printf("合并后链表L1: ");
    PrintList(L2_1);

    // 第三组数据
    LinkList L3_1, L3_2;
    int arr3_2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    InitList(&L3_1);
    CreateList_T(&L3_2, arr3_2, 10);
    printf("\n链表L1: ");
    PrintList(L3_1);
    printf("链表L2: ");
    PrintList(L3_2);

    MergeList(&L3_1, &L3_2);
    printf("合并后链表L1: ");
    PrintList(L3_1);
}

void testFindLastK()
{
    printf("\n=== 测试查找倒数第k个结点 ===\n");

    LinkList L;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    CreateList_T(&L, arr, 10);
    printf("链表: ");
    PrintList(L);

    printf("测试k=3: ");
    FindLastK(L, 3);

    printf("测试k=1: ");
    FindLastK(L, 1);

    printf("测试k=10: ");
    FindLastK(L, 10);

    printf("测试k=11: ");
    int result = FindLastK(L, 11);
    if (result == 0)
        printf("查找失败，链表长度不足11\n");
}

int main()
{
    testSplitList();
    testCommonElements();
    testRemoveDuplicates();
    testMergeList();
    testFindLastK();
    return 0;
}