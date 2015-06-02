#include <stdio.h>
#include <string.h>
#include "hextobase64.h"

void main()
{
    int i;

    char teststring[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";

    int bitarray[MAXLINE];
    int bytearray[MAXLINE];
    char base64[MAXLINE];

    int numbits, numbytes, numchars;
   
    numbits = bitArrayFromHex(teststring, bitarray);

    numbytes = byteArrayFromBits(bitarray, bytearray, numbits);

    numchars = bytesToBase64(bytearray, base64, numbytes);

    printf("\nHex: %s\n\n", teststring);
    
    printf("integer (byte) array:\n");

    for (i = 0; i < numbytes; i++)
        printf("%u ", bytearray[i]);

    printf("\n\nBase64: \n%s\n", base64);

}
