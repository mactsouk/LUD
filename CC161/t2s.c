// Programmer: Mihalis Tsoukalos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *t2s(char *line, int n)
{
    char *newLine;
	char *address;
	char c;
	int i = 0;
	int totalChars = 0;

	newLine = (char *) malloc(strlen(line) * n * sizeof(char) + 1);
	address = newLine;

	while ( (c = *line++) )	{
		if (c == '\t') {
			for (i = 0; i < n; i++) {
				*newLine++ = ' ';
				totalChars++;
			}
		}
		else {
			*newLine++ = c;
			totalChars++;
		}
	}

	// Properly terminate the string
	*newLine = '\0';
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
    
	char *myString = "\t\t\t123";
	printf("Input: __%s__\n", myString);
    printf("__%s__\n", t2s(myString, n) );
	
	myString = "1\t23\t";
	printf("Input: __%s__\n", myString);
    printf("__%s__\n", t2s(myString, n) );

    return 0;
}
