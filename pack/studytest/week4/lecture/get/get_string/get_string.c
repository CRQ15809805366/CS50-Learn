#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(4000);
    printf("Name: ");
    scanf("%s", s);
    printf("Name: %s\n", s);
    free(s);
}
