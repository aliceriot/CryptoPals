#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hexConvert.h"

// this is the first pass at doing this
// it returns the number of base64 characters written
int intToBase64(int intVals[], char base64[], int numInts)
{
    int scratchNum = 0;
    int i, j, k;
    char scratchString[MAXLINE];

    scratchNum = intVals[0];
    
    for (i = 1; i < 4; i++) {
        scratchNum <<= 8;
        scratchNum = scratchNum ^ intVals[i];
    }

    for (i = 0; i < numInts; i += 3) {
        scratchNum = intVals[i];
        for (j = i+1; j < i+4; j++) {
            scratchNum <<= 8;
            scratchNum = scratchNum ^ intVals[j];
        }
        base64String(scratchString, scratchNum);
        strcat(base64, scratchString);
        k++;
    }
    return k;
}

