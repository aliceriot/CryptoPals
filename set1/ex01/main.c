#include <stdio.h>
#include <string.h>
#include "hexConvert.h"

void main()
{
    char hex[MAXLINE] = "6F8DEA93";
    int ints[MAXLINE];
    char base64[MAXLINE];

    int hexLen, intLen, i;

    intLen = convertListToInt(hex, ints);

    for (i = 0; i < intLen; i++)
        printf("%d\t", ints[i]);

    printf("\n\n");

    hexLen = mygetline(hex, MAXLINE);

    intLen = convertListToInt(hex, ints);

    for (i = 0; i < intLen; i++)
        printf("%d\t", ints[i]);

}


