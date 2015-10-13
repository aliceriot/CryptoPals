#include <stdio.h>
#include <string.h>

unsigned int hexToBits(char hex)
{
    if ('0' <= hex && hex <= '9')
        return (hex - '0');
    else if ('A' <= hex && hex <= 'F')
        return (hex - 'A' + 10);
    else if ('a' <= hex && hex <= 'f')
        return (hex - 'a' + 10);
    else
        return 16;
}

void bitArrayFromHex(char hex[], int bitArray[])
{
    int i;
    for (i = 0; i < strlen(hex); i++)
        bitArray[i] = hexToBits(hex[i]);
}

void pairwiseXOR(unsigned int one[], unsigned int two[], int len, unsigned int result[])
{
    int i;
    
    for (i = 0; i < len; i++)
        result[i] = one[i] ^ two[i];
}

char bitsToHex(unsigned int x)
{
    if (0 <= x && x <= 9)
        return '0' + x;
    else if (10 <= x && x <= 15)
        return 'A' + x - 10;
    else
        return 'Z';
}

void hexFromBitArray(unsigned int bitArray[], int len, char hex[])
{
    int i;

    for (i = 0; i < len; i++)
        hex[i] = bitsToHex(bitArray[i]);
}

