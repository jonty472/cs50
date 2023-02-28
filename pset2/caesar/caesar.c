#include <cs50.h>
#include <errno.h>   // for errno
#include <stdlib.h>  // for strtol
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]) 
{
    if (strlen(argv[1]) == 0)
    {
        printf("empty string\n");
        return 1; // empty string
    }

    // dynamic key:
    char* p;
    long arg = strtol(argv[1], &p, 10);

    if (*p != '\0' || errno != 0) 
    {
        printf("must be digit\n");
        return 1; // In main(), returning non-zero means failure
    }
    // long to int
    int key = arg;



    string plaintext = get_string("plaintext: ");

    
    for (int i = 0; plaintext[i] != '\0'; ++i)
    {
        //printf("%i", plaintext[i]);

        int apply_cipher = (key%26) + plaintext[i];

        //  plaintext[i] < 101
        if (plaintext[i] < 'A')
        {
            printf("%c", plaintext[i]);
        }

        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            //  apply_cipher >= 141 an appyly_cipher <= 172
            if (apply_cipher >= 'a' && apply_cipher <= 'z')
            {
                printf("%c", apply_cipher);
            }
            // apply_cipher > 172
            if (apply_cipher > 'z')
            {
                int cipher_lower = (plaintext[i] - 96) - key;
                //printf("%i", cipher_calc);
                printf("%c", cipher_lower + 96);
            }
        }
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            if (apply_cipher > 'Z')
            {
                int cipher_upper = (plaintext[i] - 64) - key;
                printf("%c", cipher_upper + 64);
            }
            else
            {
                printf("%c", apply_cipher);
            }
        }
    }
    printf("\n");
}