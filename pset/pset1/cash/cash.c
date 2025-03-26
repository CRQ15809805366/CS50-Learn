#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for positive change amount
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Calculate coins needed
    const int N = 4;
    int value[] = {25, 10, 5, 1};
    int coins = 0;

    for (int i = 0; i < N; i++)
    {
        coins += cents / value[i];
        cents %= value[i]; // cents = cents % value[i] 利用greedy algorithm
    }

    // Print coins
    printf("%i\n", coins);
}
