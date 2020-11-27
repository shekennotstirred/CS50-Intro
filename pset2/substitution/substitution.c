/*
A program that implements a substitution cipher
https://cs50.harvard.edu/x/2020/psets/2/substitution/
*/

//preprocessing directives
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

//function prototypes
int is_valid_key(string);
int is_single_occurance(string, char);

int main(int argc, string argv[])
{
    //chcek if a single command-line argument key is entered
    if (argc == 2)
    {
        // check if the key entered follows specifications
        if (is_valid_key(argv[1]))
        {
            //prompt the user to enter message
            string p = get_string("plaintext: ");
            int len = strlen(p);
            string key = argv[1];

            //declare ciphertext
            char c[len];

            //encrypt message
            for (int i = 0; i < len; i++)
            {
                //if plaintext character is uppercase, substitute with the corresponding key value and convert to uppercase
                if (isupper(p[i]))
                {
                    c[i] = toupper(key[p[i] - 65]);
                }
                //if plaintext character is lowercase, substitute with the corresponding key value and convert to lowercase
                else if (islower(p[i]))
                {
                    c[i] = tolower(key[p[i] - 97]);
                }
                //if plaintext char is not alphabetical then let it remain unchanged
                else
                {
                    c[i] = p[i];
                }
            }

            //display encrypted ciphertext
            printf("ciphertext: ");
            for (int i = 0; i < len; i++)
            {
                printf("%c", c[i]);
            }
            printf("\n");
            return 0;

        }

        //prompt user to input a valid key if it is not according to the specification
        else
        {
            printf("Key must contain 26 alphabetical characters, each letter exactly once.\n");
            return 1;
        }
    }

    //prompt user for correct usage of args in case it not a single command line argument
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

//function to check if the key contains 26 alphabetical characters, each occurring exactly once
int is_valid_key(string key)
{

    //check if length of the key is 26
    if (strlen(key) != 26)
    {
        return 0;
    }

    for (int i = 0; i < 26; i++)
    {
        //check if each character in the key is alphabetical and occurs exactly once
        if (!isalpha(key[i]) || !is_single_occurance(key, key[i]))
        {
            return 0;
        }
    }
    return 1;
}


//function to check if a character occurs exactly once in a string
int is_single_occurance(string s, char c)
{
    int count = 0;

    //count the number of occurances of the char in string
    for (int i = 0; i < 26; i++)
    {
        if (s[i] == c)
        {
            count++;
        }
    }

    return (count == 1) ? 1 : 0;
}
