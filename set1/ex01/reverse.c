#include <stdio.h>

int reverse(char forward[], char backward[], int len) // pictures help yo!
{
    int i;

    for (i = 0; i <= len -2; i++)
        backward[len - (i + 2)] = forward[i];
    backward[len-1] = '\n';
    backward[len] = '\0';
}


