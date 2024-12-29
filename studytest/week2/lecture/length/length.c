#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // Prompt for user's name
    string name = get_string("Name: ");
    // Count number of characters up until '\0' (aka NUL)
    int length = strlen(name);

    printf("%i\n", length);
}
