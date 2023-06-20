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
            if this is the first jpeg
                start fwriting to img
            else (jpg already exist)
                fclose(img)
        else
            if already found jpg (001 already exists)
                keep writing to it

    fclose(img)
            
    */
    BYTE buffer[512];

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) 
    {
        printf("Could not open.\n");
        fclose(file);
        return 1;
    }

    int counter = 0;

    char filename[50];

    FILE *img = fopen(filename, "w");

    while(fread(buffer, 512, 1, file) == 1)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            // if file name doesn't exist start fwrite()
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);

                img = fopen(filename, "w");

                fwrite(buffer, 512, 1, img);

                counter++;
            }
            // else image does exist fclose() and create new file
            else if (counter > 0)
            {
                fclose(img);

                sprintf(filename, "%03i.jpg", counter);
                
                img = fopen(filename, "w");

                fwrite(buffer, 512, 1, img);

                counter++;
            }
        
        }
        else if (counter > 0)
        {
            // if image already exists start fwrite to same image
            fwrite(buffer, 512, 1, img);
            printf("continue\n");
        }
    }
    fclose(file);
    fclose(img);

}