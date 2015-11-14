#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int values[5][5] =
{
    { 1, 2, 3, 4, 5 },
    { 6, 7, 1, 2, 3 },
    { 4, 5, 6, 7, 1 },
    { 2, 3, 4, 5, 6 },
    { 7, 0, 0, 0, 0 }
};

int main(int argc, char **argv)
{
    if ( argc != 2 )
    {
        printf("Please provide the correct number of arguments!\n");
        return -3;
    }
    char *filename = argv[1];
    int result = 0;
    int totalResults = 0;
    int totalZeros = 0;
    // For accessing the two-dimensional array
    int x, y;
    // For reading each line
    char line[16];

    // Open the text file for reading
    FILE *fRead;
    fRead = fopen(filename, "r");
    if (fRead == NULL)
    {
        printf("Could not open %s!\n", filename);
        return -1;
    }
    
    // Read the text file line by line
    while(totalResults < 10000)
    {
        fgets(line,1024,fRead);
        // Remove newline character
        line[strlen(line) - 1] = '\0';
        x = atoi(line)-1;
                        
        fgets(line,1024,fRead);
        // Remove newline character
        line[strlen(line) - 1] = '\0';
        y = atoi(line)-1;
        
        // Get the random number
        result = values[x][y];
        if (result != 0)
        {
            printf("%d\n", result);
            totalResults++;
        }
        else
        {
            totalZeros++;
        }
    }
    
    printf("Total zeros: %d\n", totalZeros);
    
    // Close the file
    fclose(fRead);
    
    return 0;
}
