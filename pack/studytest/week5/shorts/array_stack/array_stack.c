#include <stdio.h>

#define CAPICITY 10

typedef struct
{
    int arr[CAPICITY];
    int top; // metadata:储存第一个空位的索引
} stack;

void push(stack *s, int item);
int pop(stack *s);

int main(void)
{
    // 初始化堆栈
    stack s;
    s.top = 0; // 第一个空位的索引是0

    // 填入元素
    for (int i = 0; i < CAPICITY; i++)
    {
        int item = 0;
        printf("Input:  ");
        scanf("%i", &item);
        push(&s, item);
    }

    printf("\n");

    // 弹出并打印元素
    for (int i = 0; i < CAPICITY; i++)
    {
        int item = pop(&s);
        printf("Output: %i\n", item);
    }
}

void push(stack *s, int item)
{
    s->arr[s->top] = item;
    s->top++;
}

int pop(stack *s)
{
    int tmp = s->top - 1;
    s->top--;
    return s->arr[tmp];
}
