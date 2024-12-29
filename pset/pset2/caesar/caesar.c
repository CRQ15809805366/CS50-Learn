#include <cs50.h>    // 储存字符串
#include <ctype.h>   // 检测数字,大小写转换
#include <stdbool.h> // 使用布尔变量
#include <stdio.h>   // 打印结果
#include <stdlib.h>  // 转换字符为数字
#include <string.h>  // 测量字符串长度

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    // For each character in the plaintext:
    const int N = strlen(plaintext);
    for (int i = 0; i < N; i++)
    {
        // Rotate the character if it's a letter
        plaintext[i] = rotate(plaintext[i], key);
    }

    printf("ciphertext: %s\n", plaintext);
}




bool only_digits(string s)
{
    int C = strlen(s);
    for (int i = 0; i < C; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (isupper(c))
    {
        c = ((c - 'A') + n) % 26 + 'A';
        return c;
    }
    else if (islower(c))
    {
        c = ((c - 'a') + n) % 26 + 'a';
        return c;
    }
    else
    {
        return c;
    }
}
