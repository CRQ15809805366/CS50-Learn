#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // 以添加模式打开一个文件, 并返回这个文件的地址给一个指向文件的指针
    FILE *file = fopen("phonebook.csv", "a");
    // 注意:当返回的地址为NULL(空地址)时, 意味着某种错误, 应当退出程序
    if (file == NULL)
        return 1;

    // Get name and number
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    // 解引用指针, 进入其指向的文件并打印对应内容
    fprintf(file, "%s,%s\n", name, number);

    // Close file
    fclose(file);
}
