#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    char buffer[512];
    
    FILE *file = fopen("text.txt", "r");
    if (file == NULL)
    {
        printf("can't open file");
        return 1;
    }

    FILE *outfile = fopen("outfile.txt", "w");

    while (fread(buffer, 1, 512, file) == 512)
    {
        fread(buffer, 1, 512, file);
        fwrite(buffer, 1, 512, outfile);
    }
    fclose(outfile);
}