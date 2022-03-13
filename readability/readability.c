#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//comment
extern size_t strlen(const char *__s);
//comment
int count_sentences(string text);
//comment
int count_characters(string text);
//comment
int count_words(string text);
//comment
int text_length;

//comment
int main(void)
{
    // get user to input a string
    string text = get_string("Text: ");
    //comment
    text_length = strlen(text);
    //comment
    int charresult = count_characters(text);
    //printf("Characters: %i\n", charresult);
    int wordresult = count_words(text);
    //printf("Words: %i\n", wordresult);
    int sentresult = count_sentences(text);
    //printf("Sentences: %i\n", sentresult);

    //comment
    double L = (double) charresult * 100 / (double) wordresult;

    //comment
    double S = (double) sentresult * 100 / (double) wordresult;

    //comment
    double index = 0.0588 * L - 0.296 * S - 15.8;

    //printf("Grade: %f\n", index);

    //comment
    index = round(index);
    //printf("Grade: %f\n", index);

    //comment
    if (index < 1)
    {
        //comment
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        //comment
        printf("Grade 16+\n");
    }
    else
    {
        //comment
        printf("Grade %i\n", (int) index);
    }
}

int count_sentences(string text)
{

    //comment
    int sentcount = 0;

    //comment
    for (int i = 0; i < text_length; i++)
    {
        //comment
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            //comment
            sentcount++;
        }
        else
        {
            //comment
            sentcount += 0;
        }
    }
    return sentcount;
}
int count_characters(string text)
{
    int chrcount = 0;
    for (int i = 0; i < text_length; i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            chrcount++;
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            chrcount++;
        }
        else
        {
            chrcount += 0;
        }
    }
    return chrcount;
}
int count_words(string text)
{
    int wordcount = 0;
    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == 32)
        {
            wordcount++;
        }
    }
    if (text_length == 0)
    {
        wordcount = 0;
    }
    else
    {
        wordcount++;
    }
    return wordcount;
}


// index = 0.0588 * L - 0.296 * S - 15.8

// where L is the average number of letters per 100 words in the text,
// and S is the average number of sentences per 100 words in the text.

