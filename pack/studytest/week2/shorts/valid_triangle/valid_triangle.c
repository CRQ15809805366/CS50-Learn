#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

bool valid_triangle(float x, float y, float z);

int main(void)
{
    const int N = 3;
    float side[N];
    for (int i = 0; i < N; i++)
    {
        side[i] = get_float("Side: ");
    }

    bool validity = valid_triangle(side[0], side[1], side[2]);

    if (validity == true)
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

bool valid_triangle(float x, float y, float z)
{
    // check for all positive sides
    if (x <= 0 || y <= 0 || z <= 0)
    {
        return false; // early return
    }

    // check for sum of any two sides greater than third
    if ((x + y) < z && (x + z) < y && (y + z) < x)
    {
        return false; // early return
    }

    // if we passed both tests, we're good!
    return true;
}

