// Programmer: Mihalis Tsoukalos

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *s2t(char *line, int n)
{
    int i, consec;
    char *address;
    char *newLine;
    
    int totalTabs = 0;
    
    newLine = (char *) malloc(strlen(line) + 1);
    address = newLine;
    
    // printf("%s\n",line);

    consec = 0;
    for (i = 0; line[i] != '\0'; ++i)
    {    
        // count consecutive spaces in a string
        if (line[i] == ' ')
            consec++;
        else
        {
            for (int j = 0; j<= consec; j++)
                *newLine++ = line[i-j];
            consec = 0;
        }

        if (consec == n)
        {
            totalTabs++;
            *newLine = '\t';
            *newLine++;
            consec = 0;
        }
    }

    // *newLine++;    
    // Properly terminate string
    *newLine = '\0';
    
    printf("Inserted %d tab(s) for %d space chars\n", totalTabs, n);
    int newSize = strlen(line)- (n-1) * totalTabs;
    printf("The output string should be %d in size\n", newSize);
    return address;
}

int main(int argc, char **argv)
{
	if ( argc != 2 )
	{
		printf("Please provide one command line argument!\n");
		return -1;
	}
	
    // Read the command line argument
	int n = atoi(argv[1]);
    
    if ( n == 0)
    {
        printf("The argument cannot be zero.\n");
        return -2;
    }
    // printf("%d spaces will be replaced by a tab\n", n);

    char *myString = "   12    4";
    
    printf("Initial string length: %zu\n", strlen(myString) );
    // printf("%s\n", s2t(myString, n));
    printf("Produced string length: %zu\n", strlen(s2t(myString, n)) );

    return 0;
}
