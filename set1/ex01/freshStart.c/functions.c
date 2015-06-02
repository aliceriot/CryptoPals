#include <stdio.h>
#include <string.h>

// get the four bits each hex represents
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

// bitArray from hex string, 
// returns number of entries in bitArray
int bitArrayFromHex(char hex[],unsigned int bitArray[])
{
    int i;
    for (i = 0; i < strlen(hex); i++)
        bitArray[i] = hexToBits(hex[i]);

    return i;
}

// takes a bit array (from above) and makes bytearray!
int byteArrayFromBits(unsigned int bitArray[],unsigned int byteArray[], int numBits)
{
    int i,j = 0;
    for (i = 0; i < numBits; i +=2) {
        byteArray[j] = (bitArray[i]<<4) | bitArray[i+1];
        j++;
    }
    return j;
}

// takes 6 bits and returns Base64 for those (6) bits
char bitsToBase64(unsigned int n)
{
    n = 63 & n; // this is a mask, we only care about first 6 bits
    if (0 <= n && n <= 25)
        return 'A' + n;
    else if (26 <= n && n <= 51)
        return 'a' + (n - 26);
    else if (52 <= n && n <= 61)
        return '0' + (n - 52);
    else if (n == 62)
        return '+';
    else if (n == 63)
        return '/';
}

// takes a byte array and converts to base64
int bytesToBase64(unsigned int bytes[], char base64[], int numbytes)
{

    int i,j;
    unsigned int temp1, temp2, threebytes;

    for (i = 0; i < numbytes; i += 3) {
        temp1 = bytes[i] << 16;
        temp2 = bytes[i+1] << 8;
        threebytes = (temp1 | temp2) | bytes[i+2];

        printf("this is threebits %u\n\n", threebytes);

        base64[j] = bitsToBase64(threebytes >> 18);
        base64[j+1] = bitsToBase64(threebytes >> 12);
        base64[j+2] = bitsToBase64(threebytes >> 6);
        base64[j+3] = bitsToBase64(threebytes);
        
        /* printf("%c",bitsToBase64(threebytes >> 18)); */
        /* printf("%c",bitsToBase64(threebytes >> 12)); */
        /* printf("%c",bitsToBase64(threebytes >> 6)); */
        /* printf("%c\t",bitsToBase64(threebytes)); */
        

        j += 4;
    }
    // edge cases here (remember we still have whatever i last was)

    // base64[++j] = '\0';
    return j;
}










