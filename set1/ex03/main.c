#include <stdio.h>
#include <string.h>
#include "xor.h"

void main()
{
    char teststring[] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    int testcounts[26];
    float testfreqs[26];
    int numchars, i;

    memset(testcounts, 0, 26 * sizeof(int));

    numchars = charCount(teststring, testcounts);
    countsToFrequency(numchars, testfreqs, testcounts);

    for (i = 0; i < 26; i++)
        printf("%d\n", testcounts[i]);
    for (i = 0; i < 26; i++)
        printf("%f\n", testfreqs[i]);
 
    printf("\n");

    int numBytes;
    int byteArray[MAXLINE];

    numBytes = hexArrayToByteArray(teststring, byteArray);
    
    for (i = 0; i < numBytes; i++)
        printf("%d\t", byteArray[i]);

}
