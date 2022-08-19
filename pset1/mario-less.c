#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("size: ");
    }

    while (n < 1);

    // for each row
    for (int i = 0; i < n; i++)
    {

        //row space
        for (int spc = n-1; spc > i; spc--)
        {
            printf(" ");
        }

        // for each column
        for (int j = 0; i >= j; j++)
        {
            printf("#");
        }

        // next row
        printf("\n");
    }

}