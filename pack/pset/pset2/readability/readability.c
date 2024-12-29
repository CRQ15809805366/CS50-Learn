#include <cs50.h>   // 获取文本
#include <ctype.h>  // 检测字母
#include <math.h>   // 四舍五入
#include <stdio.h>  // 打印结果
#include <string.h> // 测量长度

int N;

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int calculate_index(int letters, int words, int sentences);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    N = strlen(text);

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    int index = calculate_index(letters, words, sentences);

    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < N; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else
        {
            letters += 0;
        }
    }
    // Return the number of letters in text
    return letters;
}

int count_words(string text)
{
    int spaces = 0;
    for (int i = 0; i < N; i++)
    {
        if (isblank(text[i]))
        {
            spaces++;
        }
        else
        {
            spaces += 0;
        }
    }
    // Return the number of words in text
    return spaces + 1;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < N; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
        else
        {
            sentences += 0;
        }
    }
    // Return the number of sentences in text
    return sentences;
}

int calculate_index(int letters, int words, int sentences)
{
    double L = ((double) letters / (double) words) * 100;
    double S = ((double) sentences / (double) words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}
