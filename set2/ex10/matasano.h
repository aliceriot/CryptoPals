#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct cbc_cipher {
    char *iv;
    char *key;
    char *plaintext;
} cbc_cipher;

void cbc_encrypt(cbc_cipher *cbc, char *ciphertext)
{ // takes a cbc_cipher struct, performs encryption

    size_t msg_length = strlen(cbc->plaintext);
    size_t key_length = strlen(cbc->key);
    
    for (size_t i=0; i < msg_length; i++) {
        if (i < key_length)
            ciphertext[i] = cbc->plaintext[i] ^ cbc->iv[i] ^ cbc->key[i];
        else
            ciphertext[i] = cbc->plaintext[i] ^ ciphertext[i-16] ^ cbc->key[i%16];
    }
}
