#include <stdio.h>
#include <string.h>
#include "xor.h"

void main()
{
    // input string (from Matasano)
    char teststring[] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

    // byte array, number of bytes, iterator
    int byteArray[MAXLINE]; int numBytes; int i;
    numBytes = hexArrayToByteArray(teststring, byteArray);
    
    // find good keys (score < 0.06)
    int numKeys;
    int possibleKeys[256];
    numKeys = findKey(teststring, possibleKeys);

    // loop through keys, print out poss. cleartext (along with score)
    char testKeyArray[MAXLINE];;
    float score;

    for (i = 0; i < numKeys; i++) {
        xorByteArray(possibleKeys[i], numBytes, byteArray, testKeyArray);
        score = testKey(byteArray, possibleKeys[i], numBytes);
        printf("Key: %d \t Score: %f \t Message: %s\n", possibleKeys[i], score, testKeyArray);
    }
}
    
    


