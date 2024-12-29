#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number;
    do
    {
        number = get_int("Please enter a number: ");
    }
    while (number < 0);

    printf("It is %s.\n", (number % 2 == 0) ? "an even number" : "an odd number");
    return 0;
}
