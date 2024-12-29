#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool detect_phrase(string phrase);

int main(void)
{
    string phrase = get_string("Enter a phrase: ");

    // 检测是否按字母排序
    bool result = detect_phrase(phrase); // 调用函数时仅传输变量名称,无需再次声明变量类型

    // 打印结果
    if (result == true)
    {
        printf("Alphabetical order!\n");
    }
    else
    {
        printf("Not in alphabetical order!\n");
    }
}

bool detect_phrase(string phrase)
{
    // 将字符串转化为整数数组
    for (int i = 0, length = strlen(phrase); i < length - 1; i++)
    {
        if (phrase[i] + 1 != phrase[i + 1])
        {
            return false;
        }
    }
    return true;
}
