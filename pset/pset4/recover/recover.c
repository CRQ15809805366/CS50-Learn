#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512
#define JPEG_FIRST_BYTE 0xff
#define JPEG_SECOND_BYTE 0xd8
#define JPEG_THIRD_BYTE 0xff
#define JPEG_FORTHHIGHBYTE 0xe0
#define EXTRACT_HIGH_NIBBLE 0xf0
#define JPEG_NAME_SIZE 8

typedef uint8_t BYTE;

bool isjpeg(BYTE buffer[BLOCK_SIZE]);

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Invalid memory card\n");
        return 1;
    }
    // Create a buffer for a block of data
    BYTE buffer[BLOCK_SIZE];

    // Initialize file pointer to NULL
    FILE *file = NULL;

    // While there's still data left to read from the memory card
    int count = 0;
    bool lastisjpeg = false;

    while (fread(buffer, 1, BLOCK_SIZE, card) == 512)
    {
        if (isjpeg(buffer)) // 含JPEG文件头
        {
            if (count == 0) // 首个JPEG文件
            {
                // 创建文件名
                char *filename = malloc(JPEG_NAME_SIZE);
                sprintf(filename, "%03i.jpg", count);

                // 创建文件
                file = fopen(filename, "w");
                if (file == NULL)
                {
                    printf("Could not create file %s\n", filename);
                    free(filename);
                    return 1;
                }

                // 计数器加一,释放文件名
                count++;
                free(filename);

                // 写入JPEG文件
                fwrite(buffer, 1, BLOCK_SIZE, file);

                // 更新JPEG检测状态
                lastisjpeg = true;
            }

            else // 非首个JPEG文件
            {
                // 关闭上一个文件
                fclose(file);

                // 创建文件名
                char *filename = malloc(JPEG_NAME_SIZE);
                sprintf(filename, "%03i.jpg", count);

                // 创建文件
                file = fopen(filename, "w");
                if (file == NULL)
                {
                    printf("Could not create file %s\n", filename);
                    free(filename);
                    return 1;
                }

                // 计数器加一,释放文件名
                count++;
                free(filename);

                // 写入JPEG文件
                fwrite(buffer, 1, BLOCK_SIZE, file);

                // 更新JPEG检测状态
                lastisjpeg = true;
            }
        }

        else // 无JPEG文件头
        {
            if (lastisjpeg == true) // 前一个文件为JPEG文件
            {
                fwrite(buffer, 1, BLOCK_SIZE, file);
            }

            else // 前一个文件为非JPEG文件
            {
                // 更新JPEG检测状态
                lastisjpeg = false;

                // 检测下一个文件
                continue;
            }
        }
    }

    // 关闭文件
    if (file != NULL)
    {
        fclose(file);
    }

    // 关闭卡片文件
    fclose(card);

    return 0;
}

bool isjpeg(BYTE buffer[BLOCK_SIZE])
{
    if (buffer[0] != JPEG_FIRST_BYTE)
        return false;
    if (buffer[1] != JPEG_SECOND_BYTE)
        return false;
    if (buffer[2] != JPEG_THIRD_BYTE)
        return false;
    if ((buffer[3] & EXTRACT_HIGH_NIBBLE) != JPEG_FORTHHIGHBYTE)
        return false;

    return true;
}
