https://cs50.harvard.edu/x/2020/psets/1/mario/more/#:~:text=submit50%20cs50/problems/2020/x/mario/more

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

        for (int k = height - i - 1; k > 0; k--)
        {
            printf(" ");
        }

        //display i number of '#'s
        for (int j =  i + 1; j > 0; j--)
        {
            printf("#");
        }

        //display gap between pyramids
        printf("  ");

        //display i number of '#'s
        for (int j =  i + 1; j > 0; j--)
        {
            printf("#");
        }

        //go to next line
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


