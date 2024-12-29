#include <stdio.h>

int main(void)
{
    int n;
    printf("n: ");

    //  扫描用户键入内容, 作为格式化字符串储存, 然后将其转换为整数, 最后解引用n的地址, 将该整数赋给n
    scanf("%i", &n);


    printf("n: %i\n", n);
}
