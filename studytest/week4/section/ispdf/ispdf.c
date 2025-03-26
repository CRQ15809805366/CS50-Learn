#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./program filename\n");
        return 1;
    }

    string filename = argv[1];

    FILE *f = fopen(filename, "rb");
    if (f == NULL)
        return 1;

    BYTE buffer[4];
    int block_read =fread(buffer, sizeof(BYTE), 4, f);

    for (int i = 0; i < 4; i++)
        printf("%i\n" , buffer[i]);
    printf("%i\n", block_read);

    fclose(f);

    return 0;
}
