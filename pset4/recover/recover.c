#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    /*
    create buffer
    open file
    while bytes left is 512
        if buffer[0] to buffer [3] match jpg header
            fwrite buffer to image
        else
            
    */
    BYTE buffer[512];

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        printf("Could not open.\n");
        return 1;
    }
    int counter = 0;

    char filename[50];

    while(fread(buffer, 1, 512, file) == 512)
    {
        FILE *img = fopen(filename, "w");
        
        if (buffer[0] == 0xff & buffer[1] == 0xd8 & buffer[2] == 0xff)
        {

            sprintf(filename, "%03i.jpg", counter);

            fwrite(buffer, 512, 1, img);

            counter++;
        
            printf("image added\n");
        }
        else
        {
            fclose(img);
        }
    }
}