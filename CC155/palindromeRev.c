// Programmer: Mihalis Tsoukalos
// Date: Friday 15 May 2015
//
// Finding out if a word is a palindrome or not
// by comparing it to its reversed string
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 1024

// Function to Reverse a string
char * reverse(char *str)
{
    char temp;
    int i = 0;
    int j = strlen(str) - 1;
 
    while (i < j)
    {
       temp = str[i];
       str[i] = str[j];
       str[j] = temp;
       i++;
       j--;
    }
    return str;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Please use exactly one command line argument!\n");
        return -1;
    }
 
    char *word = argv[1];
    // This will hold a copy of the given word that
    // is also going to reversed later on.
    char copyRev[MAXWORD];
    strcpy(copyRev, word);
    printf("The word is %s\n", copyRev);
    
    if ( strcmp(reverse(copyRev), word) == 0)
    {
        printf("The word %s is a palindrome\n", word);
    }
    
    return 0;
}
