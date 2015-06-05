#include <stdio.h>
#include <string.h>
#include "xor.h"

void xorByteArray(int key, int numBytes, int byteArray[], char outArray[])
{
    int i;
    for (i = 0; i < numBytes; i++)
        outArray[i] = key ^ byteArray[i];
}

float testKey(unsigned int ciphertext[], unsigned int key, unsigned int numBytes)
{
    int charCounts[26];
    char testBytes[MAXLINE];
    float charFreqs[26];
    float score;
    int numchars;
    memset(charCounts, 0, 26 *sizeof(int));
    memset(charFreqs, 0.0, 26 *sizeof(float));

    xorByteArray(key, numBytes, ciphertext, testBytes);
    numchars = charCount(testBytes, charCounts);
    countsToFrequency(numchars, charFreqs, charCounts);

    score = frequencyScore(charFreqs);
    return score;
}
    
int findKey(char ciphertext[])
{
    int bestKey = 0;
    int i, numBytes;
    float bestScore, tempScore = 0.0;
    int byteArray[MAXLINE];

    numBytes = hexArrayToByteArray(ciphertext, byteArray);

    for (i = 0; i < 256; i++) {
        tempScore = testKey(byteArray, i, numBytes);
        if (tempScore > bestScore) {
            bestScore = tempScore;
            bestKey = i;
        }
    }
    return bestKey;
}
