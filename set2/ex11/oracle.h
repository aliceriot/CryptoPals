#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// CBC/ECB encryption oracle for Matasano problem 11

void random_aes_key(int numbytes, unsigned char *key)
{
    srand(time(NULL));

    for (size_t i=0; i < numbytes; i++) {
        key[i] = rand() % 256;
    }
}



