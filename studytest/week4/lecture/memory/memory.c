#include <stdlib.h>

int main(void)
{
    // 理解: 创建一个名为"x"的整数数组, 内含三个元素
    // 本质: 分配3倍于整数所需的内存, 并使用首个内存的位置创建一个指向整数的指针
        // 操作系统会自动识别整数内存的大小, 然后分别储存三个整数
    int *x = malloc(3 * sizeof(int));
    *x = 4; // 使用4 bytes储存第一个整数
    *(x + 1) = 5; // 使用4 bytes储存第二个整数
    *(x + 2) = 6; // 使用4 bytes储存第三个整数
    // 1,2 指的不是bytes, 而是特定类型所需内存(这里为4 bytes)

    free(x);
    return 0;
}