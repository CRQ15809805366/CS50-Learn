#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    cout << "输入栈的大小: ";
    int size;
    cin >> size;
    cin.ignore(); // 清除cin >> size后留下的换行符
    Stack s(size);

    cout << "输入待处理的字符串 (输入<代表退一格, 输入@代表清除到行首, 输入#结束) :" << endl;
    char ch;
    bool shouldContinue = true;
    while (shouldContinue)
    {
        // 处理一行键盘输入
        while ((ch = getchar()) != '\n')
        {
            // 处理结束输入指令
            if (ch == '#')
            {
                shouldContinue = false;
                break;
            }

            // 进行字符串处理
            switch (ch)
            {
            case '<':
                s.pop();
                break;
            case '@':
                s.setNull();
                break;
            default:
                s.push(ch);
                break;
            }
        }

        s.reverseDisplay(); // 打印本行输入
        s.setNull(); // "清空"栈, 准备储存下一行
    }

    return 0;
}