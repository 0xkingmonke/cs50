#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//global variable length of key
int keylen;
//int keyint;
string keystring;
int plaintextlength;
int isletter(string key);
int toupper(int c);
int nodupe(string key);

//initialise convert function
char convert(char character, int key);

//main substitution function
int main(int argc, string argv[])
{
    // check if more than 1 argument
    if (argc < 2)
    {
        // print error message
        printf("Usage: ./substitution key -> single argument\n");
        // return error code
        return 1;
    }
    else if (argc > 2)
    {
        // print error message
        printf("Usage: ./substitution key -> single argument\n");
        // return error code
        return 1;
    }
    else
    {
        //update global keylen variable with string lengt
        keylen = strlen(argv[1]);

        keystring = argv[1];
        //printf("%i %i\n", (int) keystring[0], (int) keystring[1]);

        bool checkifletter;

        checkifletter = isletter(keystring);
        //printf("%s\n", checkifletter ? "true" : "false");

        string upperkeystring = keystring;

        for (int m = 0; m < keylen; m++)
        {
            upperkeystring[m] = toupper(keystring[m]);
        }
        //printf("%s\n", upperkeystring);

        bool nodupes;
        nodupes = nodupe(upperkeystring);

        if (checkifletter == false || keylen != 26)
        {
            // if key not letters or not 26 char then remind to put in 26 chars.
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else if (nodupes == false)
        {
            // if key has duplicates, quit
            printf("Key must contain 26 unique characters.\n");
            return 1;
        }
        else
        {
            int upperksint[keylen];
            int upperatozint[keylen];
            int difference[keylen];

            for (int n = 0; n < keylen; n++)
            {
                upperksint[n] = (int) upperkeystring[n];
                //printf("%i\n", upperksint[n]);
            }

            int capA = 65;
            for (int p = 0; p < keylen; p++)
            {

                upperatozint[p] = capA;
                capA++;
                difference[p] = upperksint[p] - upperatozint[p];

                //printf("%i\n", difference[p]);
            }

            string plaintext = get_string("plaintext:  ");
            plaintextlength = strlen(plaintext);
            string ciphertext = plaintext;

            for (int q = 0; q < plaintextlength; q++)
            {
                if (plaintext[q] >= 'a' && plaintext[q] <= 'z')
                {
                    ciphertext[q] = plaintext[q] + difference[plaintext[q] - 'a'];
                }
                else if (plaintext[q] >= 'A' && plaintext[q] <= 'Z')
                {
                    ciphertext[q] = plaintext[q] + difference[plaintext[q] - 'A'];
                }
                else
                {
                    ciphertext[q] = plaintext[q];
                }
            }

            printf("ciphertext: %s\n", ciphertext);
            return 0;
        }

    }
}



int isletter(string key)
{
    bool result = true;
    bool resultarray[strlen(key)];

    for (int k = 0; k < strlen(key); k++)
    {
        if (key[k] >= 'a' && key[k] <= 'z')
        {
            resultarray[k] = true;
        }
        else if (key[k] >= 'A' && key[k] <= 'Z')
        {
            resultarray[k] = true;
        }
        else
        {
            resultarray[k] = false;
        }
    }

    for (int l = 0; l < strlen(key); l++)
    {
        if (resultarray[l] == false)
        {
            result = false;
        }
        else
        {
            continue;
        }
    }
    return result;
}

int nodupe(string key)
{
    bool isunique = true;
    for (int d = 0; d < strlen(key); d++)
    {
        for (int e = d + 1; e < strlen(key); e++)
        {
            if (key[d] == key[e])
            {
                isunique = false;
            }
            else
            {
                continue;
            }
        }
    }
    return isunique;
}
