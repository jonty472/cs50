#include <cs50.h>
#include <stdio.h>

int num_of_char(string text);
int num_of_letters(int text_len, string text);
int num_of_words(string text);
int num_of_sentences(string text);

int main(void) 
{
    string text = get_string("Sentence: ");
    int letters = num_of_letters(num_of_char(text), text); 
    float words = num_of_words(text);
    float sentences = num_of_sentences(text);
    
    printf("letters = %i\nwords = %f\nsentences = %f\n", letters, words, sentences);
    
    // Coleman-Liau index 
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    int index = (0.0588 * L) + (-0.296 * S) - 15.8;
    return printf("L=%f\nS=%f\ngrade:%i\n", L, S, index);
}

int num_of_char(string text)
{

    int i=0;
    while (text[i] != '\0')
    {
        ++i;
    }

    return i;
}

int num_of_letters(int text_len, string text)
{
    printf("sentence length: %i\n", text_len);

    int letters = text_len;
    for (int i = 0; i <= text_len; ++i)
    {
       if (text[i] == ' ')
       {
        --letters;
       }
    }
    return letters;
}

int num_of_words(string text)
{
    int words = 0;
    int i = 0;
    while (text[i] != '\0')
    {
        if (text[i] == ' ')
        {
            ++words;
        }
        ++i;
    }
    // +1 because loop doesn't count first word
    return words + 1;
}

int num_of_sentences(string text)
{
    int sentences = 0;
    int i = 0;
    while (text[i] != '\0')
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            ++sentences;
        }
        ++i;
    }
    return sentences;
}