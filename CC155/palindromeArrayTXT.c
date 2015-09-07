// Programmer: Mihalis Tsoukalos
// Date: Wednesday 03 June 2015
//
// Finding out if a word is a palindrome or not
// using C Arrays
//
// Reads an external text file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINESIZE 1024

int palindromeCheck(const char *s)
{
   size_t i=0, j = strlen(s);
   while (i<j && s[i]==s[--j])
       i++;
   return i>=j;
}

int main(int argc, char **argv)
{
    int linesRead = 0;
    int palindromes = 0;
    
    if (argc != 2)
    {
        printf("Please use exactly one command line argument!\n");
        return -1;
    }
 
    // Get the filename of the text file
    char *file = argv[1];
    // The variable to hold each read line
    char line[MAXLINESIZE];
    
    FILE *fp = fopen(file,"r");

    if(fp == NULL)
    {
        printf("Error reading %s\n", file);
        return 1;
    }

    while(fgets(line,1024,fp))
    {
        linesRead++;
        // Remove new line character from line
        strtok(line,"\n");
        if (palindromeCheck(line))
        {
            palindromes++;
            // printf("The word %s is a palindrome.\n", line);
        }
    }
    
    printf("Read %d lines!\n", linesRead);
    printf("Found %d palindromes!\n", palindromes);
    return 0;
}
