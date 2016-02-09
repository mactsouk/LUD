// Programmer: Mihalis Tsoukalos
//

#include <stdio.h>

long long int fibo(long long int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibo(n-1) + fibo(n-2);
}

int main(int argc, char **argv)
{
    long long int i = 0;
    for (i = 1; i < 45; i++)
        printf("Fibo(%lli) = %lli\n", i, fibo(i));
    
    if(0)
    {
        i = 10;
        printf("Should never be printed!\n");
        printf("%lli\n", i);
    }
    return 0;
}
