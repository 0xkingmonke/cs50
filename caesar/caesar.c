#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//initialise atoi function from stdlib.h to convert string to integer
extern int atoi(const char *__nptr);

//global variable length of key
int keylen;
int keyint;
string keystring;
int plaintextlength;

//initialise convert function
char convert(char character, int key);

//main caesar function
int main(int argc, string argv[])
{
    // check if more than 1 argument
    if (argc < 2)
    {
        // print error message
        printf("Usage: ./caesar key -> single argument\n");
        // return error code
        return 1;
    }
    else if (argc > 2)
    {
        // print error message
        printf("Usage: ./caesar key -> single argument\n");
        // return error code
        return 1;
    }
    else
    {
        //update global keylen variable with string lengt
        keylen = strlen(argv[1]);
        //printf("%i\n", keylen);

        //update global key variable to user key input (converted to integer)
        keyint = atoi(argv[1]);
        //printf("%i\n", keyint);

        keystring = argv[1];
        //printf("%i %i\n", (int) keystring[0], (int) keystring[1]);

        for (int i = 0; i < keylen; i++)
        {
            //printf("%i\n", (int) keystring[i]);
            if (keystring[i] < '0' || keystring[i] > '9')
            {
                // if not digit, print error message
                printf("Usage: ./caesar key\n");
                //return error code
                return 1;
            }
            else
            {
                continue;
            }

        }
        string plaintext = get_string("plaintext:  ");
        plaintextlength = strlen(plaintext);
        string ciphertext = plaintext;

        for (int j = 0; j < plaintextlength; j++)
        {
            ciphertext[j] = convert(plaintext[j], keyint);
        }

        printf("ciphertext: %s\n", ciphertext);

        return 0;

    }
}

char convert(char character, int key)
{
    if (character >= 'a' && character <= 'z')
    {
        while (key > 0)
        {
            key -= 1;
            character += 1;
            while (character > 'z')
            {
                character -= 26;
            }
        }
        return character;
    }
    else if (character >= 'A' && character <= 'Z')
    {
        while (key > 0)
        {
            key -= 1;
            character += 1;
            while (character > 'Z')
            {
                character -= 26;
            }
        }
        return character;
    }
    else
    {
        // return back symbols unchanged
        return character;
    }
}