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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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

    // 定义颜色结构体并初始化
    // 处理二进制数据的中间量要用int, 因为处理时可能使BYTE溢出
    // 最后放入原二进制数组中时,编译器隐式转换回BYTE
    typedef struct
    {
        int Gx;
        int Gy;
    } ColorValues;

    typedef struct
    {
        ColorValues Red;
        ColorValues Green;
        ColorValues Blue;
    } EdgeInfo;

    EdgeInfo pixel = {0};

    // 定义偏移量结构体并初始化
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

    // 定义权重结构体并初始化
    typedef struct
    {
        int x_wgt;
        int y_wgt;
    } wgt;

    wgt weights[9] = {
        {-1, -1}, {0, -2}, {1, -1}, // 上一行
        {-2, 0},  {0, 0},  {2, 0},  // 当前行
        {-1, 1},  {0, 2},  {1, 1}   // 下一行
    };

    // 遍历所有像素点
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // 清空边缘信息
            pixel = (EdgeInfo) {0};

            // 遍历相邻像素点
            for (int k = 0; k < 9; k++)
            {
                int x = i + offsets[k].dx;
                int y = j + offsets[k].dy;

                // 剔除超范围像素点
                if (x < 0 || x >= height || y < 0 || y >= width)
                    continue;

                // 计算边缘值
                pixel.Red.Gx += weights[k].x_wgt * copy[x][y].rgbtRed;
                pixel.Red.Gy += weights[k].y_wgt * copy[x][y].rgbtRed;
                pixel.Green.Gx += weights[k].x_wgt * copy[x][y].rgbtGreen;
                pixel.Green.Gy += weights[k].y_wgt * copy[x][y].rgbtGreen;
                pixel.Blue.Gx += weights[k].x_wgt * copy[x][y].rgbtBlue;
                pixel.Blue.Gy += weights[k].y_wgt * copy[x][y].rgbtBlue;
            }

            // 更新像素值
            image[i][j].rgbtBlue =
                fmin(round(sqrt(pixel.Blue.Gx * pixel.Blue.Gx + pixel.Blue.Gy * pixel.Blue.Gy)), 255);
            image[i][j].rgbtGreen =
                fmin(round(sqrt(pixel.Green.Gx * pixel.Green.Gx + pixel.Green.Gy * pixel.Green.Gy)), 255);
            image[i][j].rgbtRed =
                fmin(round(sqrt(pixel.Red.Gx * pixel.Red.Gx + pixel.Red.Gy * pixel.Red.Gy)), 255);
        }
    }

    return;
}
