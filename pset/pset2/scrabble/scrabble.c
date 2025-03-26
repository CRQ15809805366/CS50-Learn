#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int Calculate_score(string word);

int main(void)
{
    // 获取单词输入
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // 计算得分
    int score1 = Calculate_score(word1);
    int score2 = Calculate_score(word2);

    // 比较并输出赢家
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int Calculate_score(string word)
{
    const int N = strlen(word);

    // 转换为大写字母
    for (int i = 0; i < N; i++)
    {
        word[i] = toupper(word[i]);
    }

    // 计算总分
    int score = 0;
    for (int i = 0; i < N; i++)
    {
        if (word[i] >= 65 && word[i] <= 90)
        {
            score += POINTS[word[i] - 65];
        }
        else
        {
            score += 0;
        }
    }
    return score;
}
