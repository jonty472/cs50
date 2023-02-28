#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[]) 
{

    /*
    array of the keys
    for input plaintext[i]
        if plaintext[i] == islower()
            int AlphabetLetterNumber = plaintext[i] - 96 
        else
            plaintext[i] - 122
        
        for NumberInAlphabet
            CipherLetter = Key[NumberInAlphabet]
            return printf('%c', CipherLetter)
        
        printf("\n")
    
    */
    string plaintext = "hello world";
    string Key = "VCHPRZGJNTLSKFBDQWAXEUYMOI";

    int KeyLibrary[26];

    for (int i=0; Key[i] != '\0'; i++)
    {
        KeyLibrary[i] = Key[i];
    }
    for (int i=0; plaintext[i] != '\0'; ++i)
    {   
        if (plaintext[i] == ' ' || plaintext[i] == ',' || plaintext[i] == '.')
        {
            printf("%c", plaintext[i]);
        }
        if (islower(plaintext[i]))
        {
            int AlphabetLetterNumber = plaintext[i] - 97;
            int CipherText = tolower(Key[AlphabetLetterNumber]);
            printf("%c", CipherText);
        }
        else
        {
            int AlphabetLetterNumber = plaintext[i] - 65;
            int CipherText = Key[AlphabetLetterNumber];
            printf("%c", CipherText);
        }
    }
    printf("\n");
}