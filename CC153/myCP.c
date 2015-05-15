//
//  myCP.c
//  Implementing the UNIX cp utility
//
//  Created by Mihalis Tsoukalos on 30/03/2015.
//

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int myCP(char *file1, char *file2)
{
    FILE *fRead, *fWrite;
    fRead = fopen(file1, "r");
    fWrite = fopen(file2, "w");
    
    if (fRead == NULL)
    {
        printf("Could not open %s!\n", file1);
        return -1;
    }
    if (fWrite == NULL)
    {
        printf("Could not create %s!\n", file2);
        return -1;
    }
    
    size_t l1;
    unsigned char buffer[8192];
    while ( (l1 = fread(buffer, 1, sizeof buffer, fRead)) > 0 )
    {
        size_t l2 = fwrite(buffer, 1, l1, fWrite);
        if ( l2 != l1)
        {
            printf("There was an error: %zu <> %zu\n", l1, l2);
        }
    }
    fclose(fRead);
    fclose(fWrite);
    return 0;
}

int main(int argc, char **argv)
{
    if ( argc != 3 )
    {
        printf("Please provide the correct number of arguments!\n");
        exit(-3);
    }
    char *input = argv[1];
    char *output = argv[2];
    return myCP(input, output);
}
