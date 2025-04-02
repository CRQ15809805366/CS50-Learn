    #include "Stack.h"
    #include <iostream>
    #include <string.h>

    using namespace std;

    bool isPalindromic(Stack *reverseStr, char *sourceStr);

    int main()
    {
        Stack *str = new Stack(MAX_SIZE);

        cout << "输入字符串:" << endl;

        char ch;
        char sourceString[MAX_SIZE]; // 存储原始输入
        memset(sourceString, '\0', MAX_SIZE); // 清零整个数组
        int count = 0;               // 用于存储字符个数

        while (true)
        {
            // 读取输入并存入栈和数组
            while ((ch = getchar()) != '\n' && count < MAX_SIZE - 1)
            {
                str->push(ch);
                sourceString[count++] = ch;
            }
            sourceString[count] = '\0';

            // 判断是否是回文
            if (isPalindromic(str, sourceString))
                cout << "该字符串为回文串" << endl;
            else
                cout << "该字符串非回文串" << endl;

            // 清空栈，重置数组
            str->setNull();
            
            count = 0;
            memset(sourceString, '\0', MAX_SIZE); // 清零整个数组
        }

        delete str;
        return 0;
    }

    bool isPalindromic(Stack *reverseStr, char *sourceStr)
    {
        if (reverseStr->isEmpty())
            return false; // 防止空栈访问

        char poppedChars[MAX_SIZE];
        int i = 0;

        while (!reverseStr->isEmpty())
        {
            poppedChars[i++] = reverseStr->pop();
        }
        poppedChars[i] = '\0';

        return (strcmp(poppedChars, sourceStr) == 0);
    }
