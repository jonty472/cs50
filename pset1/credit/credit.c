#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void) 
{
    long credit_card = 4003600000000014;
    long test = 4003600000000014;
    long card_number = credit_card;
    int LuhnsAlgorithm = 0;
    //length of credit card
    int CreditCardLength = 0;
    while (credit_card != 0)
    {
        credit_card = credit_card / 10;
        ++CreditCardLength;
    }
    //printf("CreditCardLength = %d\n", CreditCardLength);

    int counter = 0;

    // https://stackoverflow.com/questions/9302681/c-how-to-break-apart-a-multi-digit-number-into-separate-variables

    for (int i = 0; i < CreditCardLength; i++)
    {
        if (counter % 2 == 0)
        {
            int digit = test % 10;
            LuhnsAlgorithm += digit;
            printf("even = %i\n", digit);
            test /= 10;
        }
        if (counter % 2 == 1)
        {
            int multiply_digit = (test % 10) * 2;
            if (multiply_digit >= 10)
            {
                for (int i = 0; i <= 1; i++)
                {
                    int digit1 = multiply_digit % 10;
                    LuhnsAlgorithm += digit1;
                    printf("split = %i\n",digit1);
                    multiply_digit /= 10;
                }
                test /= 10;
            }
            else
            {
                LuhnsAlgorithm += multiply_digit;
                printf("odd = %i\n", multiply_digit);
                test /= 10;
            }
        }
        counter++;
        //printf("counter = %i\n", counter);
    }
    printf("LuhnsAlgo = %i\n", LuhnsAlgorithm);
}