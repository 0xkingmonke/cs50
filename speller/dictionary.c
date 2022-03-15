// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <math.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 262143;

// Hash table
node *table[N];

// initialise dictionary size
int dictctr = 0;

//initialise hash value
unsigned int hashv;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // hash input word
    hashv = hash(word);

    // access hash table at hash
    node *n = table[hashv];

    // traverse down linked list at hash table value hash
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    long sum = 0;
    long hash = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += toupper(word[i]);
    }
    hash = sum % N;
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //open dict file
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    // initialise new words from dictionary
    char newword[LENGTH + 1];

    //read strings from dict one at a time
    while (fscanf(file, "%s", newword) != EOF)
    {
        //create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, newword);

        //hash word to obtain hash value
        hashv = hash(newword);

        //insert node into hash table based on hashvalue
        n->next = table[hashv];

        // increase counter
        dictctr ++;
        table[hashv] = n;

    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dictctr;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate over hash table buckets
    for (int i = 0; i < N; i++)
    {
        // point node to hashtable
        node *n = table[i];
        // while loop through linked lists in bucket
        while (n != NULL)
        {
            // Make temp equal cursor;
            node *temp = n;
            // Point cursor to next element
            n = n->next;
            // free temp
            free(temp);
        }
        if (n == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
