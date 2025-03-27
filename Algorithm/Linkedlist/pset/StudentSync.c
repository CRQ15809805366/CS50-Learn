//============================================================================
// Name        : StudentSync.c
// Author      : Cao Rongqian
// Version     : 1.0
// Copyright   : (c) 2025, Cao Rongqian
// Description : 学生信息管理系统
//============================================================================

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define NO_LENGTH 20
#define NAME_LENGTH 11

/* 定义学生结构体的数据结构 */
typedef struct Student
{
    char studentNo[NO_LENGTH];
    char studentName[NAME_LENGTH];
} st;

/* 定义每条记录或节点的数据结构 */
typedef struct node
{
    struct Student data; // 数据域
    struct node *next;   // 指针域
} Node, *Link;           // Node为node类型的别名,Link为node类型的指针别名

// 定义提示菜单
void myMenu()
{
    printf(" * * * * * * * * * 菜     单 * * * * * * * * * *\n");
    printf("     1 增加学生记录            2 删除学生记录                     \n");
    printf("     3 查找学生记录            4 修改学生记录                     \n");
    printf("     5 统计学生人数            6 显示学生记录                     \n");
    printf("     7 退出系统                                     \n");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * *\n");
}

void inputStudent(Link l)
{
    printf("请输入学生学号:");
    scanf("%s", l->data.studentNo);
    printf("请输入学生的姓名:");
    scanf("%s", l->data.studentName);

    // 每个新创建的节点的next域都初始化为NULL
    l->next = NULL;
}

void inputStudentNo(char s[], char no[])
{
    printf("请输入要%s的学生学号:", s);
    scanf("%s", no);
}

void displayNode(Link head)
{
    // 填写代码，根据传入的链表head头指针，扫描链表显示所有节点的信息
    Link p = head->next;
    while (p != NULL)
    {
        printf("Student: No.%s, Name: %s\n", p->data.studentNo, p->data.studentName);
        p = p->next;
    }
}

/* 增加学生记录 */
bool addNode(Link head)
{
    Link p, q; // p,q两个节点一前一后
    Link node; // node指针指向新创建的节点

    node = (Link)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Memory allocation failed\n");
        return false;
    }
    inputStudent(node);

    q = head;
    p = head->next; // q指向head后面的第一个有效节点

    if (head->next == NULL)
    { // 处理空链表
        head->next = node;
        return true;
    }

    // 遍历链表，寻找插入点
    while (p != NULL)
    {
        if (strcmp(node->data.studentNo, p->data.studentNo) < 0)
        {
            q->next = node;
            node->next = p;
            return true;
        }
        q = p;
        p = p->next;
    }

    // 如果node的学号是最大值，插入到链表尾部
    q->next = node;
    return true;
}

bool deleteNode(Link head)
{
    // 按照给定的学号删除学生记录，如果删除成功返回true，如果没找到学号返回false

    // 输入要处理的学号
    char no[NO_LENGTH];
    inputStudentNo("删除", no);

    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    Link q = head;
    Link p = head->next;
    while (p != NULL)
    {
        if (!strcmp(p->data.studentNo, no))
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

bool queryNode(Link head)
{
    // 按照给定的学号查询学生记录，如果查找成功返回true，如果没找到学号返回false

    // 输入要处理的学号
    char no[NO_LENGTH];
    inputStudentNo("查询", no);
    Link p = head->next;

    while (p != NULL) 
    {
        if (!strcmp(p->data.studentNo, no))
            return true;
        else
            p = p->next;
    }
    return false;
}

bool modifyNode(Link head)
{
    // 按照给定的学号找到学生记录节点，如果修改成功返回true，如果没找到学号返回false

    // 输入要处理的学号
    char no[NO_LENGTH];
    inputStudentNo("修改", no);

    // q, p一前一后
    Link q = head;
    Link p = head->next;
    
    // p指向目标结点, q指向前一个结点
    while (p != NULL)
    {
        if (!strcmp(p->data.studentNo, no))
            break;
        else
        {
            q = p;
            p = p->next;
        }
    }
    
    // 未寻找到
    if (p == NULL)
        return false;
    // 寻找到
    else
    {
        // 录入修改信息
        printf("修改学生学号:");
        scanf("%s", p->data.studentNo);
        printf("修改学生的姓名:");
        scanf("%s", p->data.studentName);
        
        // 修改学生排序
        // 断开该结点
        q->next = p->next;
        p->next = NULL;

        // 重新初始化指针
        Link node = p;
        q = head;
        p = head->next;

        if (head->next == NULL)
            // 链表为空时
            head->next = node;
        else
        {
            // 循环访问链表中的所有节点
            while (p != NULL)
            {
                if (strcmp(node->data.studentNo, p->data.studentNo) < 0)
                {
                    // 如果node节点的学号比p节点的学号小，则插在p的前面，完成插入后，提前退出子程序
                    q->next = node;
                    node->next = p;
                    return true;
                }
                else
                {
                    // 如果node节点的学号比p节点的学号大，继续向后移动指针（依然保持pq一前一后）
                    q = p;
                    p = p->next;
                }
            }
            // 如果没能提前退出循环，则说明之前没有插入，那么当前node节点的学号是最大值，此时插在链表的最后面
            q->next = node;
        }

        return true;
    }
}

int countNode(Link head)
{
    // 统计学生人数，扫描链表统计节点个数，返回节点数
    Link p;
    int count = 0;
    p = head->next;

    // 填充代码
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void clearLink(Link head)
{
    Link q, p;
    q = head;
    p = head;

    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
}

int main()
{
    int select; // 选项
    int count;  // 学生个数

    Link head; // 定义链表
    // 建立head头结点，在这个程序中head指向头结点，头结点data部分没有内容，其后续节点才有真正的数据
    head = (Link)malloc(sizeof(Node));
    head->next = NULL;

    while (1) // 菜单界面一直存在
    {
        myMenu();                         // 打印菜单
        printf("\n请输入你的选择(0-7):"); // 显示提示信息
        scanf("%d", &select);             // 存储选项
        switch (select)
        {
        case 1:
            // 增加学生记录
            if (addNode(head))
                printf("成功插入一个学生记录。\n\n");
            break;
        case 2:
            // 删除学生记录
            if (deleteNode(head))
                printf("成功删除一个学生记录。\n\n");
            else
                printf("没有找到要删除的学生节点。\n\n");
            break;
        case 3:
            // 查询学生记录
            if (queryNode(head))
                printf("成功找到学生记录。\n\n");
            else
                printf("没有找到要查询的学生节点。\n\n");
            break;
        case 4:
            // 修改学生记录
            if (modifyNode(head))
                printf("成功修改一个学生记录。\n\n");
            else
                printf("没有找到要修改的学生节点。\n\n");
            break;
        case 5:
            // 统计学生人数
            count = countNode(head);
            printf("学生人数为：%d\n\n", count);
            break;
        case 6:
            // 显示学生记录
            displayNode(head);
            break;
        case 7:
            // 退出前清除链表中的所有结点
            clearLink(head);
            return 0;
        default:
            printf("输入不正确, 应该输入0-7之间的数。\n\n");
            break;
        }
    }
    return 0;
}