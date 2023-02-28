#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int my_numbers[] = {5, 2, 4, 7, 4, 1, 6, 3, 0};
    int n = 9;

    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 2; j++)
        {
            // if 5 > 2
            if (my_numbers[j] > my_numbers[j+1])
            {
                int swap = my_numbers[j+1];
                my_numbers[j+1] = my_numbers[j];
                my_numbers[j] = swap;
            }
        }
    }

    for (int i = 0; i <= n-1; i++)
    {
        printf("%i", my_numbers[i]);
    }
    printf("\n");
}