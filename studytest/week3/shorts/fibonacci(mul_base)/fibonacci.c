#include <cs50.h>
#include <stdio.h>

int fib(int f);

int main (void)
{
    int f = get_int("frequency: ");
    int item = fib(f); // the f-th item
    printf("The %ith item of fibonacci sequence is %i.\n", f ,item);
}

int fib(int f)
{
    // base case
    if (f == 1)
        return 0;
    if (f == 2)
        return 1;

    // recursion case
    return fib(f - 1) + fib(f - 2);
}
