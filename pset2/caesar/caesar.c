/*
A program to encrypt messages using Caesar's Cipher
https://cs50.harvard.edu/x/2020/psets/2/caesar/
*/

//preprocessor directives
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

//function prototypes
int is_non_neg_int(string);
int get_int_from_string(string);

int main(int argc, string argv[])
{
    //check if arguments are inputed in accordance with specifications
    if (argc == 2 && is_non_neg_int(argv[1]))
    {
        //prompt user for plaintext
        string p = get_string("plaintext: ");

        //convert key inputed as string into int for encryption
        int k = get_int_from_string(argv[1]);

        int n = strlen(p);

        //since strings are immutable, declare a character array of same length as cipher text
        char c[n];

        // encrypt message
        for (int i = 0; i < n; i++)
        {
            //calculate intermediate ciphertext as sum of plaintext char and the round-robin-ed value of key
            int cipher = p[i] + (k % 26);

            //if plaintext char is uppercase and intermediate ciphertext is out of bounds of uppercase ASCII range then round-robin in order to remain uppercase
            if (isupper(p[i]))
            {
                c[i] = (cipher > 90) ? cipher - 26 : cipher;
            }

            //if plaintext char is lowercase and intermediate ciphertext is out of bounds of lowercase ASCII range then round-robin in order to remain lowercase
            else if (islower(p[i]))
            {
                c[i] = (cipher > 122) ? cipher - 26 : cipher;
            }

            //if plaintext char is not alphabetical then let it remain unchanged
            else
            {
                c[i] = p[i];
            }
        }

        //display encrypted ciphertext
        printf("ciphertext: ");
        for (int i = 0; i < n; i++)
        {
            printf("%c", c[i]);
        }
        printf("\n");
        return 0;
    }

    //prompt user for correct usage of args in case it is not inputed according to specs
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

//function to check if the inputted string is a non-negative integer
int is_non_neg_int(string s)
{
    int n = strlen(s);

    /*the number of decimal bits needed to represent the
    maximum integer value of 2^31 - 26 is not greater than 10*/
    if (n > 10)
    {
        return 0;
    }

    //check if each character of the string is a decimal digit
    for (int i = 0; i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return 0;
        }
    }
    return 1;
}

//function to convert an numerical string to an integer
int get_int_from_string(string s)
{
    int num = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //calculate decimal value of numerical character
        int digit = s[i] - 48;

        //convert each extracted digit into integer
        num = num * 10 + digit;
    }
    return num;
}