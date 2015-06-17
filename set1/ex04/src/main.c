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
    strcat(fileLoc, "../hex.txt");

    char *stringArray[1000];
    int numLines;
    numLines = loadFile(fileLoc, stringArray);

    int bestLine;
    int goodLines[327];
    memset(goodLines, 0, 327*sizeof(int));
    bestLine = methodTwoLoop(stringArray, numLines, goodLines);
    
    int byteArray[MAXLINE]; int numBytes; int i; int j = 0;

    for (i = 0; i < 327; i++)
        printf("Line: %d frequencyFilter: %d\n", i, frequencyFilter(stringArray[i]));

    /* int line; */
    /* for (i = 0; i < 327; i++) { */
    /*     line = goodLines[i]; */
    /*     if (line == 0) */
    /*         break; */

    /*     printf("--------------------------\n"); */
    /*     numBytes = hexArrayToByteArray(stringArray[line], byteArray); */

    /*     int numKeys; */
    /*     int possibleKeys[256]; */
    /*     numKeys = findKey(stringArray[line], possibleKeys); */

    /*     char testKeyArray[MAXLINE]; */
    /*     float score; */

    /*     printf("Line: %d Keys: %d\n", line, numKeys); */

    /*     for (j = 0; j < numKeys; j++) { */
    /*         xorByteArray(possibleKeys[j], numBytes, byteArray, testKeyArray); */
    /*         score = testKey(byteArray, possibleKeys[j], numBytes); */
    /*         printf("Key: %d \t Score: %f \t Message: %s\n", possibleKeys[j], score, testKeyArray); */
    /*     } */
    /* } */
        
}
