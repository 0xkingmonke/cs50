#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get user to input name, store as string variable name
    string name = get_string("What's your name? ");
    // print concatenated string "hello, " and users name
    printf("hello, %s\n", name);
}