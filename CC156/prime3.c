// Programmer: Mihalis Tsoukalos
// Date: Friday 12 June 2015
//
// Find prime numbers up to a limit
// The limit is given as a command line argument

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TOTAL = 0;

int isPrime(int number)
{
    if (number == 1)
        return 1;
    
    if (number == 2)
        return 1;
    
    int i = 0;
    float temp = number/2.0;
    int j = (int) temp;
    
    for (i=2; i<=j; i++)
    {
        TOTAL++;
        if (number % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char** argv)
{
    int i = 0;
    int total = 0;
    
    // Get the integer as string and convert it to integer
    int limit = atoi(argv[1]);

    // Find prime numbers
    for (i=3; i<=limit; i=i+2)
    {
        TOTAL++;
        if (isPrime(i))
        {
            total++;
        }
    }
    
    printf("Found %d primes from 3 up to %d.\n", total, limit);
    printf("Total number of computations: %d.\n", TOTAL);
    
    return 0;
}
