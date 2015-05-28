#include <stdio.h>
#include <string.h>
#include "hexConvert.h"

void main()
{
    char hex[MAXLINE];
    int ints[MAXLINE];
    char base64[MAXLINE];

    int hexLen, intLen;


    ints[0] = 456;

    hexLen = mygetline(hex, MAXLINE);
    printf("%d\n",strlen(hex));
    printf("%c\t%d\t\n",hex[0], hex[1], hex[2]);
    printf("\nblah\n");
    printf("%d\n",returnNum((char) hex[0]));
    printf("%d\n",returnNum((char) hex[1]));

    char small[3];
    printf("%d\n", hexToInt(hex,3));

    intLen = convertListToInt(hex, ints);

    printf("%d\t%d\n", ints[0], ints[1]);

}


