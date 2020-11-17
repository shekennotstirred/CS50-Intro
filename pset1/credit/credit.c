/*
Credit- a progrram that prompts the user for a credit card number and then reports it's validity per the Luhn's algorithm
https://cs50.harvard.edu/x/2020/psets/1/credit/
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int get_sum_digits(int);

int main(void)
{
    //prompt user for credit card number
    long card = get_long("Number: ");
    long credit_card = card;
    int i = 1, odd_sum = 0, even_sum = 0, p;

    //luhn's algorithm
    while (card > 0)
    {
        //calculate sum of odd digits from the right
        if (i % 2 != 0)
        {
            odd_sum += (card % 10);
        }

        //multiply even digits from the right by 2 and calculate sum of sum of the product's digits
        else
        {
            p = 2 * (card % 10);
            even_sum += get_sum_digits(p);
        }
        card /= 10;
        i++;
    }

    //if the final sum doesn't end with zero, display invalid
    if (((odd_sum + even_sum) % 10) != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        // find the first 2 starting digits of credit card
        int leading_digits = (int)((double)credit_card / pow((double)10, (double)(i - 3)));
        int length = i - 1;

        // display card type if valid per definitions, otherwise invalid
        if (length == 15 && (leading_digits == 34 || leading_digits == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && (leading_digits > 50 && leading_digits < 56))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && (leading_digits > 39 && leading_digits < 50))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

// find sum of digits of a number
int get_sum_digits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += (num % 10);
        num /= 10;
    }

    return sum;
}