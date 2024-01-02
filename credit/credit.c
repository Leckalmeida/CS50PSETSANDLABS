#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for credit card number
    long card_number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number <= 0);

    // Calculate checksum using Luhn's algorithm
    int sum = 0, digit_count = 0;
    long num = card_number;

    while (num > 0)
    {
        // Get the last digit
        int digit = num % 10;
        num /= 10;

        // Double every other digit starting from the second-to-last
        if (digit_count % 2 != 0)
        {
            digit *= 2;

            // Add the digits of the product (if greater than 9)
            digit = (digit / 10) + (digit % 10);
        }

        // Add the digit to the sum
        sum += digit;
        digit_count++;
    }

    // Check if the card number is valid
    if (sum % 10 == 0)
    {
        // Determine the card type
        while (card_number >= 100)
        {
            card_number /= 10;
        }

        // Check for specific card types
        if ((card_number == 34 || card_number == 37) && digit_count == 15)
        {
            printf("AMEX\n");
        }
        else if ((card_number >= 51 && card_number <= 55) && digit_count == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ((card_number >= 40 && card_number <= 49) && (digit_count == 13 || digit_count == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
