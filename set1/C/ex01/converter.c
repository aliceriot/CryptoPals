#include <stdio.h>
#include <string.h>
#include "hexConvert.h"

// this does the actual conversion (lol)

int convertListToInt(char hex[], int intVals[])
{
    int i,j = 0;

    for (i=0; i < strlen(hex); i+= 2)
        intVals[j++] = hexToInt(hex[i], hex[i+1]);

    return j;
}

int convertListToBase64(int ints[], char base64[])
{
    printf("Blah");
    return 0;
}
