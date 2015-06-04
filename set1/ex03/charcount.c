#include <stdio.h>
#include <string.h>
#include "xor.h"

int charCount(char string[], int counts[])
{
    int count = 0;
    char cur;
    int i;

    for (i=0; i < strlen(string); i++) {
        cur = string[i];
        if ('A' <= cur & cur <= 'Z') {
            counts[cur - 'A'] += 1;
            count++;
        }
        else if ('a' <= cur & cur <= 'z') {
            counts[cur - 'a'] += 1;
            count++;
        }
    }
    return count;
}

void countsToFrequency(int totalChars, float frequencies[], int counts[])
{
    int i;
    for (i=0; i < 26; i++) {
        frequencies[i] = (float)counts[i] / totalChars;
    }
}

// need to write the frequency score function
