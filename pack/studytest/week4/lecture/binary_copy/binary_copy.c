#include <stdio.h>
#include <stdint.h>

// 八位无符号整数
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "rb"); // read binary 二进制读取
    FILE *dst = fopen(argv[2], "wb"); // write binary 二进制写入

    BYTE b;

    // 对文件srv进行读取, 每次读取一单位, 每单位为b的字节大小(1bytes)
    // 并解引用b的地址, 进入并把读取的数据放入b内部
    // 返回读取成功了几个单位,当返回0时,意味着达到srv的末尾
    while (fread(&b, sizeof(b), 1, src) != 0)

        // 对文件dst进行写入, 每次写入一单位, 每单位为b的字节大小(1bytes)
        // 并解引用b的地址, 进入并将b储存的数据写入dst
        fwrite(&b, sizeof(b), 1, dst);
}
