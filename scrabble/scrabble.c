#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// comments
int toupper(int c);
// comments
int compute_score(string word);
// comments
int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 == score2)
    {
        printf("Tie!");
    }
    // comments
    else if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    // comments
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    // comments
    else
    {
        printf("Error!\n");
    }
}

int compute_score(string word)
{
    // comments
    int arraypos = 0;
    // comments
    int letterscore = 0;
    // comments
    int wordscore = 0;
    // comments
    int capsword[strlen(word)];
    // comments
    for (int m = 0; m < strlen(word); m++)
    {
        capsword[m] = toupper(word[m]);
    }
    // comments
    for (int i = 0; i < strlen(word); i++)
    {
        if (capsword[i] >= 'A' && capsword[i] <= 'Z')
        {
            arraypos = capsword[i] - 'A';
            letterscore = POINTS[arraypos];
        }
        else
        {
            letterscore = 0;
        }
        wordscore += letterscore;
    }
    // comments
    return wordscore;
}
