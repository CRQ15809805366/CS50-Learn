#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            BYTE avg =
                round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            // Update pixel values
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            BYTE sepiaRed = fmin(round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                       .189 * image[i][j].rgbtBlue),
                                 255);
            BYTE sepiaGreen = fmin(round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                         .168 * image[i][j].rgbtBlue),
                                   255);
            BYTE sepiaBlue = fmin(round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                        .131 * image[i][j].rgbtBlue),
                                  255);

            // Update pixel with sepia values
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    typedef struct
    {
        int dx;
        int dy;
    } Offset;

    Offset offsets[9] = {
        {-1, -1}, {0, -1}, {1, -1}, // 上一行
        {-1, 0},  {0, 0},  {1, 0},  // 当前行
        {-1, 1},  {0, 1},  {1, 1}   // 下一行
    };

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float blueSum = 0, greenSum = 0, redSum = 0;
            float count = 0;

            for (int k = 0; k < 9; k++)
            {
                int x = i + offsets[k].dx;
                int y = j + offsets[k].dy;
                if (x < 0 || x > height - 1 || y < 0 || y > width - 1)
                    continue;
                count++;

                blueSum += copy[x][y].rgbtBlue;
                greenSum += copy[x][y].rgbtGreen;
                redSum += copy[x][y].rgbtRed;
            }

            image[i][j].rgbtBlue = round(blueSum / count);
            image[i][j].rgbtGreen = round(greenSum / count);
            image[i][j].rgbtRed = round(redSum / count);
        }
    }

    return;
}
