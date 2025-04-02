#include "Stack.h"

Stack::Stack()
{
    size = MAX_SIZE;
    top = -1;
    data = new char[MAX_SIZE];
}
Stack::Stack(int s)
{
    size = s;
    top = -1;
    data = new char[size];
}
Stack::~Stack()
{
    delete[] data;
}

void Stack::push(char ch) // 压栈
{

    if (isFull())
        throw Full();
    else
        data[++top] = ch;
}
char Stack::pop() // 出栈并返回出栈元素
{
    if (isEmpty())
        throw Empty();
    else
        return data[top--];
}
char Stack::getTop() // 获取栈顶元素
{
    if (isEmpty())
        throw Empty();
    else
        return data[top];
}
bool Stack::isEmpty() // 判断栈是否为空
{
    if (top == -1)
        return true;
    else
        return false;
}
bool Stack::isFull() // 判断栈是否为满
{
    if (top == size - 1)
        return true;
    else
        return false;
}
void Stack::setNull() // 将栈设置为空
{
        top = -1;        
}

void Stack::reverseDisplay()
{
    if (isEmpty())
    {
        cout << "栈为空" << endl;
        return;
    }

    for (int i = 0; i <= top; i++)
    {
        cout << data[i];
    }
    cout << endl;
}