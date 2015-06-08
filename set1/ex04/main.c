#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "detection.h"

void main()
{
    // just the first one from the file
    char teststring[] = "0e3647e8592d35514a081243582536ed3de6734059001e3f535ce6271032";
    char teststring2[] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

    char fileLoc[MAXLINE];
    getcwd(fileLoc, MAXLINE);
    strcat(fileLoc, "/4.txt");

    char *stringArray[1000];
    int numLines;
    numLines = loadFile(fileLoc, stringArray);

    int bestLine;
    int goodLines[327];
    memset(goodLines, 0, 256*sizeof(int));
    bestLine = methodTwoLoop(stringArray, numLines, goodLines);
    
    int byteArray[MAXLINE]; int numBytes; int i; int j = 0;

    int line;
    for (i = 0; i < 327; i++) {
        line = goodLines[j];
        if (line == 0)
            break;
        printf("--------------------------\n");
        printf("Line %d\n", line);
        numBytes = hexArrayToByteArray(stringArray[line], byteArray);

        int numKeys;
        int possibleKeys[256];
        numKeys = findKey(stringArray[line], possibleKeys);

        char testKeyArray[MAXLINE];
        float score;

        printf("%d", goodLines[j]);
        printf("%d", numKeys);

        for (i = 0; i < numKeys; i++) {
            xorByteArray(possibleKeys[i], numBytes, byteArray, testKeyArray);
            score = testKey(byteArray, possibleKeys[i], numBytes);
            printf("Key: %d \t Score: %f \t Message: %s\n", possibleKeys[i], score, testKeyArray);
        }
    }
        
}
