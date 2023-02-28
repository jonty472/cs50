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
        //left side pyramid
        for (int spc = n-1; spc > i; spc--)
        {
            printf(" ");
        }

        for (int j = 0; i >= j; j++)
        {
            printf("#");
        }

        // half the pyramid
        printf(" ");

        // right-side pyramid
        for (int z = 0; z <= i; ++z)
        {
            printf("#");
        }
        // next row
        printf("\n");
    }

}