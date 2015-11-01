@ This is my solution to exercise 11 of the Matasano challenges. Basically, here
we're asked to produce an ECB/CBC detection oracle. In other words, we want to write a
program that will be able to tell whether we're encrypting in ECB or CBC, without
any knowledge of the plaintext.

Great! Let's get started. First, a bunch of includes:

@c
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <openssl/ssl.h>

@ I think first we'll need a function to generate a random key for AES. This is because
our encryption oracle can't have any knowledge about what the encryption key is, and
we'd like to use a different one every time.

Let's try this out: we'll take a number of random bytes, and a pointer into which to throw
them.

@c
void random_bytes(int numbytes, unsigned char *output)
{
    srand(time(NULL));

    for (size_t i=0; i < numbytes; i++) {
        output[i] = rand() % 256;
    }
}
