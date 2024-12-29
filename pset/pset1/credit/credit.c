#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

#define SUCCESS 0
#define INVALID_CARD -1

typedef enum { INVALID, AMEX, MASTERCARD, VISA } card_type;

#define AMEX_LENGTH 15
#define VISA_LENGTH_13 13
#define VISA_LENGTH_16 16
#define MC_LENGTH 16

#define AMEX_PREFIX_1 34
#define AMEX_PREFIX_2 37
#define MC_PREFIX_MIN 51
#define MC_PREFIX_MAX 55
#define VISA_PREFIX 4

// Improved function prototypes with const qualifiers
static long get_card_number(void);
static int calculate_checksum(const long number);
static int get_digit_count(const long number);
static int get_starting_digits(const long number, const int length);
static card_type detect_card_type(const int digit_count, const int starting_digits);
static bool is_valid_length(const int digit_count);

int main(void)
{
    const long number = get_card_number();
    if (number < 0)
    {
        printf("INVALID\n");
        return INVALID_CARD;
    }

    if (calculate_checksum(number) % 10 != 0)
    {
        printf("INVALID\n");
        return INVALID_CARD;
    }

    const int digit_count = get_digit_count(number);
    const int starting_digits = get_starting_digits(number, digit_count);
    const card_type type = detect_card_type(digit_count, starting_digits);

    switch (type)
    {
        case AMEX:
            printf("AMEX\n");
            break;
        case MASTERCARD:
            printf("MASTERCARD\n");
            break;
        case VISA:
            printf("VISA\n");
            break;
        default:
            printf("INVALID\n");
            break;
    }

    return SUCCESS;
}

static card_type detect_card_type(const int digit_count, const int starting_digits)
{
    // Early return if invalid length
    if (!is_valid_length(digit_count))
    {
        return INVALID;
    }

    // Check AMEX first (most specific conditions)
    const int first_two_digits = starting_digits;
    if (digit_count == AMEX_LENGTH &&
        (first_two_digits == AMEX_PREFIX_1 || first_two_digits == AMEX_PREFIX_2))
    {
        return AMEX;
    }

    // Check Mastercard
    if (digit_count == MC_LENGTH &&
        (first_two_digits >= MC_PREFIX_MIN && first_two_digits <= MC_PREFIX_MAX))
    {
        return MASTERCARD;
    }

    // Check VISA last (most general condition)
    const int first_digit = first_two_digits / 10;
    if ((digit_count == VISA_LENGTH_13 || digit_count == VISA_LENGTH_16) &&
        first_digit == VISA_PREFIX)
    {
        return VISA;
    }

    return INVALID;
}

static long get_card_number(void)
{
    long number;
    int attempts = 0;
    const int MAX_ATTEMPTS = 3;

    do
    {
        number = get_long("Number: ");
        if (++attempts >= MAX_ATTEMPTS)
        {
            return -1; // Return error after max attempts
        }
    }
    while (number <= 0 || get_digit_count(number) > VISA_LENGTH_16);

    return number;
}

static int calculate_checksum(const long number)
{
    int sum = 0;
    long num = number;
    bool multiply = false;

    while (num > 0)
    {
        int digit = num % 10;

        if (multiply)
        {
            digit *= 2;
            sum += (digit > 9) ? (digit - 9) : digit;
        }
        else
        {
            sum += digit;
        }

        multiply = !multiply;
        num /= 10;
    }

    return sum;
}

static int get_digit_count(const long number)
{
    int count = 0;
    long num = number;
    while (num > 0)
    {
        count++;
        num /= 10;
    }
    return count;
}

static int get_starting_digits(const long number, const int length)
{
    long num = number;
    int len = length;
    while (len > 2)
    {
        num /= 10;
        len--;
    }
    return num;
}

static bool is_valid_length(const int digit_count)
{
    return digit_count == AMEX_LENGTH || digit_count == VISA_LENGTH_13 ||
           digit_count == VISA_LENGTH_16;
}
