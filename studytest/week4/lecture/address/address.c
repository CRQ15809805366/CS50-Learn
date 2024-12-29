#include <stdio.h>

typedef char *string;

int main(void)
{
// 这些只是底层细节, 只要记住char *string, 然后照常运用string即可
    // 创建一个名为s的指针, 指向一个字符变量
    // 创建一个常字符数组 HI!(\0)
    // 获取该数组第一个元素的地址, 并将其赋给s
        // 数组名称本质是指针
        // index本质是指针运算
        // 因此数组不按值传递
        // 调用字符串指针数时,若不指明index, 则默认从首位开始, 直至\0结束
        // 识别到字符串指针后,自动添加*(dereference)

    string s = "HI!";
    printf("%c", *s);
    printf("%c", *(s + 1));
    printf("%c\n", *(s + 2));
}
