// Programmer: Mihalis Tsoukalos
// Date: Friday 15 May 2015
//
// Finding out if a word is a palindrome or not
// using C Arrays

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromeCheck(const char *s)
{
   size_t i=0, j = strlen(s);
   while (i<j && s[i]==s[--j])
       i++;
   return i>=j;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Please use exactly one command line argument!\n");
        return -1;
    }
 
    char *word = argv[1];
    if ( palindromeCheck(word) )
    {
        printf("The word %s is a palindrome\n.", word);
    }
    
    return 0;
}
