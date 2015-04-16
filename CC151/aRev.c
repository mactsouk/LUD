// The array version of reverse string

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char s[] = "abcdefg";
    const int len = strlen(s);
    int i, max;
    char temp;
    
    printf("Before: %s\n", s);

    if ( len % 2 == 1 )
    {
        // Odd
        max = (len+1) / 2 - 1;
    }
    else
    {
        // Even
        max = len / 2;
    }
    
    for (i=0; i<max; i++)
    {   
        temp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = temp;
    }
  
    printf("After:  %s\n", s);
    return 0;
}
