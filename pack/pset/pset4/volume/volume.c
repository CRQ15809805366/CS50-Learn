// Modifies the volume of an audio file

#include <stdint.h> // include uint8_t type
#include <stdio.h>
#include <stdlib.h>

void copy_header(FILE *input, FILE *output);
void update_data(FILE *input, FILE *output, float factor);

typedef uint8_t BYTE;
typedef int16_t TWOBYTES;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    copy_header(input, output);

    // TODO: Read samples from input file and write updated data to output file
    update_data(input, output, factor);

    // Close files
    fclose(input);
    fclose(output);
}

void copy_header(FILE *input, FILE *output)
{
    BYTE header[HEADER_SIZE];
    fread(header, sizeof(BYTE), HEADER_SIZE, input);
    fwrite(header, sizeof(BYTE), HEADER_SIZE, output);
}

void update_data(FILE *input, FILE *output, float factor)
{
    TWOBYTES buffer;
    // treats non-zero values as true and zero values as false
    while (fread(&buffer, sizeof(TWOBYTES), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(TWOBYTES), 1, output);
    }
}
