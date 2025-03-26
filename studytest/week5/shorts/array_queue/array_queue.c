#include <stdio.h>

#define CAPICITY 10

typedef struct
{
    int arr[CAPICITY];
    int front; // 出队用:储存最先进入的元素的索引(也可视为即将弹出的元素的索引)
    int size; // 入队用:储存队列大小(也可视为即将进入的元素的索引)
} queue;

void enqueue(queue *q, int item);
int dequeue(queue *q);

int main(void)
{
    // 初始化队列
    queue q;
    q.front = 0;
    q.size = 0;

    // 填入元素
    for (int i = 0; i < CAPICITY; i++)
    {
        int item = 0;
        printf("Input:  ");
        scanf("%i", &item);
        enqueue(&q, item);
    }

    printf("\n");

    // 弹出并打印元素
    for (int i = 0; i < CAPICITY; i++)
    {
        int item = dequeue(&q);
        printf("Output: %i\n", item);
    }
}

void enqueue(queue *q, int item)
{
    q->arr[q->size] = item;
    q->size++;
}

int dequeue(queue *q)
{
    int tmp = q->front;
    q->front++;
    q->size--;
    return q->arr[tmp];
}
