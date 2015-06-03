#include <stdio.h>
#include <string.h>
#include "fixedXOR.h"

int main()
{
    char hexOne[] = "1c0111001f010100061a024b53535009181c";
    char hexTwo[] = "686974207468652062756c6c277320657965";

    char shouldget[] = "746865206b696420646f6e277420706c6179";

    unsigned int bitsOne[MAXLINE]; // bit arrays for
    unsigned int bitsTwo[MAXLINE]; // hexOne and Two

    unsigned int result[MAXLINE]; // XOR result
    char hexThree[MAXLINE]; //output

    int len = strlen(hexOne);
    if (len != strlen(hexTwo)) {
        printf("Error! Inequal string lengths!\n");
        return -1;
    }

    bitArrayFromHex(hexOne, bitsOne);
    bitArrayFromHex(hexTwo, bitsTwo);

    pairwiseXOR(bitsOne, bitsTwo, len, result);

    hexFromBitArray(result, len, hexThree);

    printf("\nOk, so we should get:\n%s\n\n", shouldget);
    printf("And we actually got:\n%s\n", hexThree);

}

