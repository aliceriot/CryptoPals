#include <stdio.h>
#include <string.h>
#include "detection.h"

void xorByteArray(int key, int numBytes, int byteArray[], char outArray[])
{
    int i;
    for (i = 0; i < numBytes; i++)
        outArray[i] = key ^ byteArray[i];
}

float testKey(unsigned int ciphertext[], unsigned int key, unsigned int numBytes)
{
    if ((key ^ ciphertext[0]) >= 128) // if it's not ascii we're done
        return -1.0;
    else {
        int charCounts[26];
        char testBytes[MAXLINE];
        float charFreqs[26];
        float score;
        int numchars;
        int i;
        memset(charCounts, 0, 26 *sizeof(int));
        memset(charFreqs, 0.0, 26 *sizeof(float));

        xorByteArray(key, numBytes, ciphertext, testBytes);

        for (i =0; i < numBytes; i++) {
            if (testBytes[i] >= 128)
                return -1.0;
        }

        numchars = charCount(testBytes, charCounts);
        countsToFrequency(numchars, charFreqs, charCounts);

        score = frequencyScore(charFreqs);
        return score;
    }
}
    
int findKey(char ciphertext[], int keyArray[])
{
    int bestKey = 0;
    int i, numBytes;
    float bestScore, tempScore = 0.0;
    int byteArray[MAXLINE];
    int j = 0;

    numBytes = hexArrayToByteArray(ciphertext, byteArray);

    bestScore = testKey(byteArray, 0, numBytes);

    for (i = 1; i < 256; i++) {
        tempScore = testKey(byteArray, i, numBytes);
        if (tempScore < 0.06 && tempScore > 0.0)
            keyArray[j++] = i;
    }
    return j;
}
