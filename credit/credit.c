#include <cs50.h>
#include <stdio.h>
#include <math.h>

// referencing checksum function with input num as argument and output checksum
int checksum(long long num);
// referencing validity of checksum result
bool validity(int checksum);
// referencing check digits
int checkdigits(long long num);
// referencing get digits, to get nth digit of number
int getdigit(long long num, int n);
// referencing get first 2 digits, to get first2 digit of number
int getheader(long long num);
long long get_long(long long input);

int main(void)
{
    // declare ccnum variable
    long long ccnum;
    // do while loop to force user to input correctly
    do
    {
        // get user input for digits
        ccnum = get_long("Number: ");
    }

    // if ccnum is negative or not numeric, repeat prompt
    while (ccnum < 0);

    // check digits
    int digits = checkdigits(ccnum);
    //**printf("%i\n", digits);

    // if 13,15 or 16 digits proceed to checksum"
    if (digits == 13 || digits == 15 || digits == 16)
    {
        //declare boolean isv and equal to checksum result on ccnum (which returns true or false)
        bool isv;
        isv = checksum(ccnum);
        if (isv)
        {
            //if checksum valid, check for header

            // declare type for first 2 digits
            int type = 0;

            // reference type to getheader function on ccnum
            type = getheader(ccnum);
            //printf("%i\n", type);
            //check for mastercard header
            if (type >= 50 && type <= 55)
            {
                printf("MASTERCARD\n");
            }
            //check for visa header
            else if (type >= 40 && type <= 49)
            {
                printf("VISA\n");
            }
            //check for amex header
            else if (type == 34 || type == 37)
            {
                printf("AMEX\n");
            }
            // if none, invalid
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            // if checksum invalid, return invalid + new line
            printf("INVALID\n");
        }
    }

    // else return "INVALID" + new line
    else
    {
        printf("INVALID\n");
    }

}

int checksum(long long num)
{
    int digits = checkdigits(num);
    int dblsum = 0;
    int singlesum = 0;
    int totalsum = 0;

    //** check digits
    //printf("%i\n", digits);

    // start from second last number, decrease by 2
    for (int i = 1; i <= digits; i += 2)
    {
        // find digit, add 2x n to dblsum
        //printf("%i\n", getdigit(num, i));
        if (getdigit(num, i) >= 5 && getdigit(num, i) <= 9)
        {
            int x = getdigit(2 * getdigit(num, i), 0);
            int y = getdigit(2 * getdigit(num, i), 1);
            int z = x + y;
            dblsum += z;
        }
        else
        {
            dblsum += 2 * (getdigit(num, i));
        }
    }
    ///** check singlesum
    //printf("%i\n", dblsum);

    // start from last number, decrease by 2
    for (int j = 0; j <= digits; j += 2)
    {
        // find digit, add i to singlesum
        singlesum += getdigit(num, j);
    }
    ///** check dblsum
    //printf("%i\n", singlesum);

    // add dblsum to singlesum, find totalsum
    // return totalsum
    totalsum = singlesum + dblsum;

    //printf("%i\n", totalsum);
    bool isvalid = validity(totalsum);

    return isvalid;

}

bool validity(int checksum)

{
    // take input totalsum from checksum
    // mod totalsum by 10
    // check remainder
    // return valid (true) or invalid (false)
    if (checksum % 10 == 0)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

int checkdigits(long long num)
{
    int count = 0;

    // iterate at least once, then until num becomes 0
    // remove last digit from num in each iteration
    // increase count by 1 in each iteration
    do
    {
        num /= 10;
        count++;
    }
    while (num != 0);
    return count;
}

int getdigit(long long num, int n)
{
    long long r = num / pow(10, n);
    //printf ("%lli  ",r);
    int q = r % 10;
    //printf ("%i  ",q);
    return q;
}

int getheader(long long num)
{
    // initialise d for number of digits
    int d = checkdigits(num);
    //printf ("%i\n", d);

    //initialise header as first two digits
    int header = 0;
    // initialise arbitrary counter for power of 10 division
    int counter = 0;

    for (int k = d - 2; k < d; k++)
    {
        // loop twice, get first two digits, to 10^1 and 10^0 respectively, sum up
        header += pow(10, counter) * getdigit(num, k);
        header = (int) header;
        //printf ("%i\n", k);
        //printf ("%f\n", pow(10,counter));
        //printf ("%i\n", getdigit(num,k));
        //printf ("%i\n", header);
        counter += 1;
    }
    return header;
}