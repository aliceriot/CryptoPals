#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// this will before CBC block encryption/decryption with repeating-key
// XOR (Vigenere's cipher).
//
// Input to the `cbc_cipher` struct should already be decoded (e.g. from
// base64, hex, etc).

typedef struct cbc_cipher {
    unsigned char *iv;
    unsigned char *key;
    unsigned char *plaintext;
    unsigned char *ciphertext;
} cbc_cipher;

void cbc_encrypt(cbc_cipher *cbc)
{ // takes a cbc_cipher struct, performs encryption

    size_t msg_length = strlen(cbc->plaintext);
    size_t key_length = strlen(cbc->key);
    
    for (size_t i=0; i < msg_length; i++) {
        if (i < key_length)
            cbc->ciphertext[i] = cbc->plaintext[i] ^ cbc->iv[i] ^ cbc->key[i];
        else
            cbc->ciphertext[i] = cbc->plaintext[i] ^ cbc->ciphertext[i-16] ^ cbc->key[i%16];
    }
}

void cbc_decrypt(cbc_cipher *cbc)
{ // takes a cbc_cipher struct, performs encryption

    size_t msg_length = strlen(cbc->ciphertext);
    size_t key_length = strlen(cbc->key);
    
    for (size_t i=0; i < msg_length; i++) {
        if (i < key_length)
            cbc->plaintext[i] = cbc->ciphertext[i] ^ cbc->iv[i] ^ cbc->key[i];
        else
            cbc->plaintext[i] = cbc->ciphertext[i] ^ cbc->ciphertext[i-16] ^ cbc->key[i%16];
    }
}
