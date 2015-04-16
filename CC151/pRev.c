// The pointer version of reverse string

#include <stdio.h>

int main(int argc, char **argv)
{
    char s[] = "abcdefg123";
    int len = 0;
    char temp;
    int i = 0;

    // Get memory address of the first element
    char *p = &s[0];
    
    // Find the end of the string and its length
    while ( *p++ )
    {
        len++;
        // printf("%s\n", p);
    }
    // Return to the last character
    p = p-2;

    // Now reverse the string using pointer arithmetic
    while ( (p != &s[i]) && (p - &s[i] > 0))
    {
        temp = s[i];
        s[i] = *p;
        *p = temp;
        p--;
        i++;
    }

    printf("%s\n", s);
    return 0;
}
