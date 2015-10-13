#include <stdio.h>
#include <string.h>
#include "xor.h"

unsigned int hexToBits(char hex)
{
    if ('0' <= hex && hex <= '9')
        return hex - '0';
    else if ('A' <= hex && hex <= 'F')
        return hex - 'A' + 10;
    else if ('a' <= hex && hex <= 'f')
        return hex - 'a' + 10;
    else
        return 16;
}

int hexArrayToByteArray(char hex[], int bytes[])
{
    int i,j = 0;
    int temp1, temp2;

    for (i=0; i<strlen(hex); i+=2) {
        temp1 = hexToBits(hex[i]);
        temp2 = hexToBits(hex[i+1]);
        temp1 <<= 4;
        temp1 = temp1 | temp2;
        bytes[j++] = temp1;
    }
    return j;
}


