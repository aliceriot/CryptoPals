#include <stdio.h>
#include <string.h>
#include <math.h>
#include "xor.h"

// ''normal'' English character frequency from wikipedia
static float english[26] = 
   {0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 
    0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 
    0.02406, 0.06749, 0.07507, 0.01929, 0.00095, 0.05987,
    0.06327, 0.09056, 0.02758, 0.00978, 0.02361, 0.00150,
    0.01974, 0.00074};

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

float frequencyScore(float frequencies[])
{
    int i;
    float difference, score = 0.0;

    for (i=0; i < 26; i++) {
        difference = frequencies[i] - english[i];
        score += pow(difference, 2.0);
    }
    return score;
}

