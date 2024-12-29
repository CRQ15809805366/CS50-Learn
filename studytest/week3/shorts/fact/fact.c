#include <cs50.h>
#include <stdio.h>

int fact(int n);

int main(void)
{
    int n = get_int("n = ");
    int factorial = fact(n);
    printf("%i\n", factorial);
}

int fact(int n)
{
    // base case
    if (n == 1)
        return 1;
    // recursion base
    return n * fact(n - 1);
}
