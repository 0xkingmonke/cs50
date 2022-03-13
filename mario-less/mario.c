    #include <cs50.h>
    #include <stdio.h>

    int main(void)
    {

        int n;

        do
        {
            // Prompt user for height,
            n = get_int("Height: ");
        }
        // if height is less than 1 or greater than 8 (or not an integer at all), go back one step
        while (n < 1 || n > 8);

        // Iterate from 1 through height:
        for (int i = 1; i <= n; i++)
        {
            for (int j = n; j > i; j--)
            {
                // On iteration i, print n-i dashes
                printf(" ");
            }
            for (int k = 1; k <= i; k++)
            {
                // On iteration i, print i hashes and then a newline
                printf("#");
            }
            printf("\n");
        }


    }