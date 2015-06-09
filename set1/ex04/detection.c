#include <stdio.h>
#include <string.h>
#include "detection.h"

// returns one if the most common byte can be XOR'ed to A, T, or E
int frequencyFilter(char hexstring[])
{
    int freqArray[256];
    int i;
    int byteArray[MAXLINE];
    int mostFrequentByte = 0;
    int numbytes;

    numbytes = hexArrayToByteArray(hexstring, byteArray);
    memset(freqArray, 0, 256*sizeof(int));

    for (i = 0; i < numbytes; i++) {
        freqArray[byteArray[i]] += 1;
    }
    
    for (i = 0; i < 256; i++) {
        if (freqArray[i] > mostFrequentByte)
            mostFrequentByte = i;
    }
    printf("\nMost frequent byte: %d\n", mostFrequentByte);

    int foundOne = 0;

    for (i = 0; i < 256; i++) {
        if ((mostFrequentByte ^ i) == 'e')
            foundOne = 1;
        else if ((mostFrequentByte ^ i) == 'E')
            foundOne = 1;
        else if ((mostFrequentByte ^ i) == 'a')
            foundOne = 1;
        else if ((mostFrequentByte ^ i) == 'A')
            foundOne = 1;
        else if ((mostFrequentByte ^ i) == 't')
            foundOne = 1;
        else if ((mostFrequentByte ^ i) == 'T')
            foundOne = 1;
    }
    return foundOne;
}

















float methodTwo(char ciphertext[])
{
    int keyArray[256];
    int numKeys, i;

    // get all the 'good' keys
    numKeys = findKey(ciphertext, keyArray);

    // get the sum!
    float sum = 0.0;
    float tempScore;
    int byteArray[MAXLINE];

    int numBytes;
    numBytes = hexArrayToByteArray(ciphertext, byteArray);

    for (i = 0; i < numKeys; i++) {
        tempScore = testKey(byteArray, keyArray[i], numBytes);
        sum += tempScore;
    }
    return sum;
}

int methodTwoLoop(char *stringArray[], int numLines, int goodLines[])
{
    int i, bestLine;
    float bestSoFar = 1.0;
    float tempScore;
    int j = 0;

    for (i = 0; i < numLines; i++) {
        tempScore = methodTwo(stringArray[i]);
        if (tempScore < bestSoFar && tempScore > 0.0) {
            bestSoFar = tempScore;
            bestLine = i;
        }
        else if (tempScore > 0.0 && tempScore < 1)
            goodLines[j++] = i;
    }
    return bestLine;
        //printf("Line: %d Score: %f\n", i, methodTwo(stringArray[i]));
}

int loadFile(char fileLocation[], char *stringArray[])
{
    FILE *hexStrings;
    hexStrings = fopen(fileLocation, "r");
    char filebuffer[FILEBUF];

    int numlines = 0;
    int i;
    char *p, stringBuffer[62];

    p = &filebuffer[0];
    while (fgets(stringBuffer, 62, hexStrings)){
        stringBuffer[60] = '\0';
        strcpy(p, stringBuffer);
        stringArray[numlines++] = p;
        p += 62;
    }
    fclose(hexStrings);
    return numlines;
} 
