#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct polynomial
{
    int coefficient; // 系数
    int exp;         // 指数
    struct polynomial *next;
} Node, *Link;

void inputPoly(Link head);                             // 用于从控制台读入链表的函数
void print(Link head);                                 // 打印链表用的函数
bool insert(Link head, int coefficient, int exp);      // 向链表插入一个元素的函数
void combin2List(Link heada, Link headb, Link headab); // 合并两个链表
void clearList(Link head);                             // 释放链表

int main()
{
    Link headA, headB; // 两个多项式的头指针
    Link headAB;       // 合并后的多项式的头指针

    /*链表的初始化*/
    headA = (Link)malloc(sizeof(Node));
    headA->next = NULL;
    headB = (Link)malloc(sizeof(Node));
    headB->next = NULL;
    headAB = (Link)malloc(sizeof(Node));
    headAB->next = NULL;

    printf("请输入第一个多项式的系数和指数，以(0 0)结束：\n");
    inputPoly(headA);
    printf("第一个");
    print(headA);
    printf("请输入第二个多项式的系数和指数，以(0 0)结束：\n");
    inputPoly(headB);
    printf("第二个");
    print(headB);

    combin2List(headA, headB, headAB);
    printf("合并后");
    print(headAB);

    clearList(headA);
    clearList(headB);
    clearList(headAB);
    return 0;
}

/**输入二项式数据的函数*/
/*这个函数用来输入二项式，给用户合适的提示，读入用户输入的系数和指数。
调用函数insert，将用户输入的二项式的一项插入到链表中去。*/
void inputPoly(Link head)
{
    int coefficient, exp; // 系数和指数
    printf("请输入系数和指数(如：\"2 3\"表示2x^3): ");
    scanf("%d %d", &coefficient, &exp);
    while (coefficient != 0 || exp != 0) // 系数和指数其中一个不为0
    {
        insert(head, coefficient, exp); // 调函数插入多项式
        /* 连续输入多个系数和指数 */
        printf("请输入系数和指数：");
        scanf("%d %d", &coefficient, &exp);
    }
}

/**向多项式链表中插入元素的函数
int coefficient 一个多项式项的系数
int exp 一个多项式项的幂
*/
bool insert(Link head, int coefficient, int exp)
{
    Link node; // node指针指向新创建的节点
    Link q, p; // q,p两个节点一前一后

    // 创建一个新结点
    node = (Link)malloc(sizeof(Node));
    node->coefficient = coefficient;
    node->exp = exp;
    node->next = NULL;

    // 初始化工具指针
    q = head;
    p = head->next;

    if (head->next == NULL) // 空表,插第1个
    {
        head->next = node;
    }
    else
    {
        /*循环访问链表中的所有节点*/
        while (p != NULL)
        {
            // 如果node节点的指数比p节点的指数大，则插在p的前面，完成插入后，提前退出
            if (node->exp > p->exp)
            {
                q->next = node;
                node->next = p;
                return true;
            }
            // 如果node节点的指数和p节点的指数相等，则合并这个多项式节点，提前退出
            if (node->exp == p->exp)
            {
                p->coefficient += node->coefficient;
                free(node);
                return true;
            }
            // 如果node节点的指数比p节点的指数小，继续向后移动指针（依然保持p，q一前一后）
            if (node->exp < p->exp)
            {
                q = p;
                p = p->next;
            }
        }
        // 如果退出循环是当前指针p移动到链表结尾，则说明之前没有插入，那么当前node节点的指数值是最小值，此时插在链表的最后面
        if (p == NULL)
        {
            q->next = node;
        }
    }
    return true;
}

/**
 * @brief 打印多项式链表
 *
 * 该函数用于打印多项式的链表表示，格式化输出每一项的系数和指数。
 *
 * @details
①　通过指针访问链表
②　多重条件语句嵌套
③　数字转换为字符串函数sprintf
④　标志是否为第一个节点的flag的设置
⑤　字符串连接函数strcat
⑥　字符串清空函数memset. memset(item,0,20); 清空长20的字符串item
 *
 * @param head 指向多项式链表头节点的指针
 * @return 无返回值，直接输出到标准输出
 */
void print(Link head)
{
    Link p; // 指向链表要输出的结点
    printf("多项式如下：\n");
    p = head->next;

    if (p == NULL)
    {
        printf("多项式为空\n");
        return;
    }
    // 不是空表
    char item[20] = "";  // 要打印的当前多项式的一项
    char number[7] = ""; // 暂时存放系数/指数转换成的字符串

    bool isFirstItem = true; // 标志是否为第一个节点的flag
    // 打印节点
    do
    {
        memset(item, 0, sizeof(item)); // 清空字符串item

        /*处理符号*/
        // 第一项 & 系数正 -> 不打符号
        // 第一项 & 系数负 -> 不打符号(系数自带符号)
        // 非首项 & 系数正 -> 打正号
        // 非首项 & 系数负 -> 不打符号(系数自带符号)
        if ((!isFirstItem) && (p->coefficient > 0))
            strcat(item, "+");

        /*处理系数*/
        // 系数为1 -> 不打系数
        // 系数为-1 -> 打印负号
        // 系数为0 -> 不打系数
        // 系数不为0, 1或-1 -> 打印系数
        if (p->coefficient == -1)
            strcat(item, "-");
        else if ((p->coefficient != 1) && (p->coefficient != -1) && (p->coefficient != 0))
        {
            sprintf(number, "%d", p->coefficient); // 先转换整数到 number
            strcat(item, number);                  // 再追加到 item 里
        }

        /*处理常数项*/
        // 如果指数为0
        if (p->exp == 0)
        {
            // 系数是-1或1 -> 打1(负号已打完)
            if (p->coefficient == -1 || p->coefficient == 1)
                strcat(item, "1");
            // 系数不为1或-1 -> 不打x与指数
        }

        /*处理x*/
        // 指数不为0, 系数不为0
        if ((p->exp != 0) && (p->coefficient != 0))
            strcat(item, "x"); // 打印x

        /*处理指数*/
        // 如果指数为0或1, 或系数为0，不打指数，否则打指数
        if ((p->exp != 0) && (p->exp != 1) && (p->coefficient != 0))
        {
            strcat(item, "^");
            sprintf(number, "%d", p->exp); // 先转换整数到 number
            strcat(item, number);          // 再追加到 item 里
        }

        printf("%s", item);  // 打印当前节点代表的项
        p = p->next;         // 指向下个结点
        isFirstItem = false; // flag标志不是第一项了
    } while (p != NULL);
    printf("\n");
    return;
}

/**
合并两个有序链表a，b到链表ab
heada.headb,headab分别为链表a,b,ab的头指针
*/
void combin2List(Link heada, Link headb, Link headab)
{
    Link pa, pb; // 指向a，b链表和ab的指针
    pa = heada->next;
    pb = headb->next;

    while (pa != NULL && pb != NULL) // a,b链表都没有没有访问完毕
    {
        // 如果指数a>指数b，a节点插入ab链表，a指针后移
        if (pa->exp > pb->exp)
        {
            insert(headab, pa->coefficient, pa->exp);
            pa = pa->next;
        }
        // 如果指数a<指数b，b节点插入ab链表，b指针后移
        if (pa->exp < pb->exp)
        {
            insert(headab, pb->coefficient, pb->exp);
            pb = pb->next;
        }
        // 如果指数a==指数b，a、b系数相加，插入ab链表，a、b指针后移
        if (pa->exp == pb->exp)
        {
            if ((pa->coefficient + pb->coefficient) != 0)
                insert(headab, (pa->coefficient + pb->coefficient), pa->exp);
            pa = pa->next;
            pb = pb->next;
        }
    }
    // 如果a、b链表还有尾巴，将它加到ab链表后面
    while (pa != NULL)
    {
        insert(headab, pa->coefficient, pa->exp);
        pa = pa->next;
    }
    while (pb != NULL)
    {
        insert(headab, pa->coefficient, pa->exp);
        pa = pa->next;
    }
    return;
}

void clearList(Link head)
{
    Link p = head->next;
    while (p != NULL)
    {
        head->next = p->next;
        free(p);
        p = head->next;
    }
    free(head);
}