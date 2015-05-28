#include <stdio.h>
#include <string.h>

// this does the actual conversion (lol)

int convertList(char hex[], int intVals[], char base64[])
{
    int i,j = 0;
    char scratch[2];

    for (i=0; i < strlen(hex); i+= 2) {
        scratch[0] = hex[i];
        scratch[1] = hex[i+1];
        intVals[i] = hexToInt(scratch, 2);
        j++;
    }
    return j;
}
