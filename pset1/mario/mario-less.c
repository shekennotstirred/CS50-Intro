#include <stdio.h>
#include <cs50.h>

int get_height(void);

int main(void)
{
    //prompt user for pyramid's height
    int height = get_height();

    //display pyramid
    for (int i = 0; i < height; i++)
    {
        //display height-i-1 spaces first
        int k = height - i - 1;
        while (k > 0)
        {
            printf(" ");
            k--;
        }

        //display i number of '#'s
        for (int j =  i + 1; j > 0; j--)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_height(void)
{
    //input positive integer between 1 and 8 inclusive
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    return h;
}


