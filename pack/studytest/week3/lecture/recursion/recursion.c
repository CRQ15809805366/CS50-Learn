#include <cs50.h>
#include <stdio.h>

void draw(int height);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    // base case
    if (n == 1)
    {
        printf("#");
        printf("\n");
        return;
    }
    // recursion base

        // Print pyramid of height n - 1
    draw(n - 1);

        // Print one more row
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
