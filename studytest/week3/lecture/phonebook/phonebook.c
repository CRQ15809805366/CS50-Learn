#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} person;

int main(void)
{
    const int N = 3;
    person people[N];
    people[0].name = "laojie";
    people[0].number = "+86-121-3812-1381";
    people[1].name = "laobing";
    people[1].number = "+86-148-7985-4589";
    people[2].name = "huoying";
    people[2].number = "+86-115-0815-4585";

    string name = get_string("Name: ");
    for (int i = 0; i < N; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
