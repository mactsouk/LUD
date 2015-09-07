// Programmer: Mihalis Tsoukalos
// Date: Friday 15 May 2015
//
// Finding out if a word is a palindrome or not
// using C pointers.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromeCheck(const char *s)
{
    const char *t = s + strlen(s);
    while (s<t && *s==*--t)
        s++;
    return s>=t;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Please use exactly one command line argument!\n");
        return -1;
    }
 
    // Get the word
    char *word = argv[1];
    
    if ( palindromeCheck(word) )
    {
        printf("The word %s is a palindrome\n.", word);
    }
    
    return 0;
}
