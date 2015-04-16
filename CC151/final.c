// The Final version of reverse string

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char s[] = "abcdefg1";
    const int len = strlen(s);
    int i = 0;
    char temp;
    char *p = &s[len-1];
    
    printf("Before: %s\n", s);
    
    for (i=0; i < len/2; i++)
    {
        temp = s[i];
        s[i] = *p;
        *p = temp;
        p--;
    }
    
    printf("After:  %s\n", s);
    
    return 0;
}
