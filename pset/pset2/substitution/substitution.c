#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool validate_key(string key);
void encipher(string plaintext, string key);

int main(int argc, string argv[])
{
    // Get key
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    // Validate key
    if (!validate_key(argv[1]))
    {
        return 1;
    }
    string key = argv[1];

    // Get plaintext
    string plaintext = get_string("plaintext:  ");

    // Encipher
    encipher(plaintext, key);

    // Print ciphertext
    printf("ciphertext: %s\n", plaintext);
}

bool validate_key(string key)
{
    const int N = 26; // 26  letters
    int n = strlen(key);

    // Check key length
    if (n != N)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    // Check for non-alphabetic characters
    for (int i = 0; i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }
    }

    // Check for repeated characters(case-intensive)
    for (int j = 0; j < n; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            if (tolower(key[j]) == tolower(key[k]))
            {
                printf("Key must not contain repeated characters.\n");
                return false;
            }
        }
    }
    return true;
}

void encipher(string plaintext, string key)
{
    // For each alphabetic character, determine what letter it maps to
    const int COUNTER = strlen(plaintext);
    for (int i = 0; i < COUNTER; i++)
    {
        // Preserve case
        if (isupper(plaintext[i]))
        {
            plaintext[i] = toupper(key[plaintext[i] - 'A']);
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i] = tolower(key[plaintext[i] - 'a']);
        }
        // Leave non-alphabetic characters as-is
    }
}
