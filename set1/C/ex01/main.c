#include <stdio.h>
#include <string.h>
#include "hexConvert.h"

void main()
{
    char hex[MAXLINE] = "49276d";
    int ints[MAXLINE];
    char base64[MAXLINE];

    int hexLen, intLen, i, baseVal;

    intLen = convertListToInt(hex, ints);

    for (i = 0; i < intLen; i++)
        printf("%d\t", ints[i]);

    printf("\n\n");

    /* hexLen = mygetline(hex, MAXLINE); */

/*     intLen = convertListToInt(hex, ints); */

/*     for (i = 0; i < intLen; i++) */
/*         printf("%d\t", ints[i]); */


    baseVal = intToBase64(ints, base64, intLen);

    printf("\n%s\n", base64);

    int thing = 73;
    char scratch1[MAXLINE];

    base64String(scratch1, thing);

    printf("\n%s\n", scratch1);

}


