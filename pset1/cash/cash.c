/*
Cash - a program that first asks the user how much change is owed and then prints the minimum number of coins with which that change can be made.
https://cs50.harvard.edu/x/2020/psets/1/cash/
*/
#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_change(void);

int main(void)
{
    int no_of_coins = 0;
    int denominations[4] = {25, 10, 5, 1};

    //prompt user for change owed
    float dollars = get_change();

    //convert dollars to cents
    int cents = round(dollars * 100);

    //calculate minimum coins needed
    for (int i = 0; i < 4; i++)
    {
        no_of_coins += (cents / denominations[i]);
        cents %= denominations[i];
    }

    //display minimum number of coins needed
    printf("%i\n", no_of_coins);
}


//input non-negative float
float get_change(void)
{
    float ch;
    do
    {
        ch = get_float("Change owed: ");
    }
    while (ch < 0.00);

    return ch;
}