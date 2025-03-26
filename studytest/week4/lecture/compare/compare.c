#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    printf("%p\n", s);
    printf("%p\n", s + 1);
    printf("%p\n", t);
    printf("%p\n", t + 1);
}
