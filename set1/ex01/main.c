#include <stdio.h>
#include <string.h>
#include "hexConvert.h"

void main()
{
    char hexVals[MAXLINE];
    int intVals[MAXLINE];
    char base64Vals[MAXLINE];

    int len, i, numInts;
    
    len = mygetline(hexVals, MAXLINE);

    numInts = convertList(hexVals, intVals, base64Vals);

    for (i=0; i < numInts; i++) {
        printf("%d\n", intVals[i]);
    }
    printf("%d\n", hexToInt("6f", 2));
}
     

