/*
A program that prompts user to input some text and returns
the approximate grade level needed to comprehend the text
based on the Coleman Liau Index
https://cs50.harvard.edu/x/2020/psets/2/readability/
*/

//preprocessor directives
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

//function prototype
void displayGrade(int);

int main(void)
{
    //prompt for text using get_string
    string text = get_string("Text: ");

    //initialize number of letters, words, sentences in text
    int l = 0, w = 1, s = 0;

    //count number of letters, words, sentences in text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //letters
        if (isalpha(text[i]))
        {
            l++;
        }
        //words
        else if (isspace(text[i]))
        {
            w++;
        }
        //sentences
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            s++;
        }
    }

    //compute Coleman Liau Index
    float L = 100 * (float)l / (float)w;
    float S = 100 * (float)s / (float)w;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    //output approximate grade level
    displayGrade(round(index));
}

void displayGrade(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

/*
//function to count the number of letters [a-z A-Z] in the input string
int count_letters(string s)
{
    int letters = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        letters += isalpha(s[i]) ? 1 : 0;
    }

    return letters;
}


//function to count the number of words in the input string
int count_words(string s)
{
    //assuming input doesn't start or end with a space
    //so there is 1 word by default
    int words = 1;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        words += isspace(s[i]) ? 1 : 0;
    }

    return words;
}

int count_sentences(string s)
{
    int sentences = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        sentences += (s[i] == '.' || s[i] == '?' || s[i] == '!') ? 1 : 0;
    }

    return sentences;
}
*/


