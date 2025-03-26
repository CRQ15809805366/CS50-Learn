#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    int votes;
} candidate;

int main (void)
{
    const int num_candidates = 3;
    candidate candidates[num_candidates];

    candidates[0].name = "Carter";
    candidates[0].votes = 10;

    candidates[1].name = "Yuliia";
    candidates[1].votes = 12;

    candidates[2].name = "Carter";
    candidates[2].votes = 7;

    // Find the highest number of votes
        // selection sort first step
    int highest_votes = 0;
    for (int i = 0; i < num_candidates; i++)
    {
        if (candidates[i].votes > highest_votes)
            highest_votes = candidates[i].votes;
    }

    // Print name of candidate with highest number of votes
    for (int j = 0; j < num_candidates; j++)
    {
        if (candidates[j].votes == highest_votes)
            printf("%s\n", candidates[j].name);
    }
}
