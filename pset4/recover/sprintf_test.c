#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(void)
{
    int counter = 0;
    char filename[50];
    for (int i = 0; i < 5; i++)
    {
        int result = sprintf(filename, "%03i.jpg", counter);
        FILE *outfile = fopen(filename, "w");
        printf("%i\n", result);
        counter++;
    }
}