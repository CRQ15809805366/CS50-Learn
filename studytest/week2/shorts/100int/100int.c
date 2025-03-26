#include <stdio.h>
#include <cs50.h>

const int NUMBER = 100;

// 对于array的处理,无需return value,因为array是一个global value
void set_integer(int array[NUMBER]);
void print_integer(int array[NUMBER]);

int main(void)
{
    int integer[NUMBER];
    set_integer(integer);
    print_integer(integer);
}

void set_integer(int array[NUMBER])
{
    for (int i = 0; i < NUMBER; i++)
    {
        array[i] = i;
    }
}

void print_integer(int array[NUMBER])
{
    for (int i = 0; i < NUMBER; i++)
    {
        printf("%i\n", array[i]);

    }
}
