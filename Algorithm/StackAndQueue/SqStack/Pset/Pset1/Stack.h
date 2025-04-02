#ifndef STACK_H // 如果未定义 STACK_H
#define STACK_H // 定义 STACK_H，防止重复包含

#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class Stack
{
private:
    char *data; // 指向数组的指针
    int size;   // 数组的大小
    int top;    // 栈顶

public:
    // 异常内部类
    class Empty
    {
    };
    class Full
    {
    };

    Stack();
    Stack(int s);
    ~Stack();

    void push(char ch);    // 压栈
    char pop();            // 出栈并返回出栈元素
    char getTop();         // 获取栈顶元素
    bool isEmpty();        // 判断栈是否为空
    bool isFull();         // 判断栈是否为满
    void setNull();        // 将栈设置为空
    void reverseDisplay(); // 从栈底至栈顶打印元素
};

#endif // 结束宏定义