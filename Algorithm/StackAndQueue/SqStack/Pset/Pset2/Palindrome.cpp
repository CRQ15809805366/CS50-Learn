#include "Stack.h"
#include <iostream>

bool isPalindromic(Stack& str);

int main()
{
    Stack str(MAX_SIZE);

    cout << "输入字符串 :" << endl;
    getchar(); // 清除endl的输入缓冲区污染, 避免被后续getchar读取为'\n'
    char ch;
    while (true)
    {
        // 将一行输入全部压入栈
        while ((ch = getchar()) != '\n')
        {
            str.push(ch);
        }
        
        // 判断堆栈内的字符串是否为回文串
        if (isPalindromic(str))
            cout << "该字符串为回文串" << endl;
        else
            cout << "该字符串非回文串" << endl;

        // "清空"栈(将栈顶归位, 但储存不动), 准备储存下一行
        str.setNull(); 
    }
    
    return 0;
}

bool isPalindromic(Stack& str)
{

}