#include <stdio.h>
#include <string.h>
#include "hexConvert.h"

// this does the actual conversion (lol)

int convertListToInt(char hex[], int intVals[])
{
    int i,j = 0;
    char scratch[3];

    for (i=0; i < strlen(hex); i+= 2) {
        scratch[0] = hex[i];
        scratch[1] = hex[i+1];
        intVals[j] = hexToInt(scratch, 2);
        j++;
    }
    return j;
}

int convertListToBase64(int ints[], char base64[])
{
    printf("Blah");
    return 0;
}
