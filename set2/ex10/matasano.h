#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <openssl/aes.h>

// this will perform CBC block encryption/decryption with AES-128
// We're using OpenSSL in EBC mode.
//
// Input to the `cbc_cipher` struct should already be decoded (e.g. from
// base64, hex, etc).

typedef struct cbc_cipher {
    unsigned char *iv;
    unsigned char *key;
    unsigned char *plaintext;
    unsigned char *ciphertext;
    unsigned int input_length;
} cbc_cipher;

void cbc_decrypt(cbc_cipher *cbc)
{ // takes a cbc_cipher struct, performs decryption

    // we're going to do something with this!
    EVP_CIPHER_CTX ctx;

    EVP_CIPHER_CTX_init(&ctx);
    EVP_DecryptInit_ex(&ctx, EVP_aes_128_ecb(), cbc->key, cbc->iv);

    /* size_t key_length = strlen(cbc->key); */

    /* for (size_t i=0; i < cbc->input_length; i++) { */
    /*     if (i < key_length) */
    /*         cbc->plaintext[i] = cbc->ciphertext[i] ^ cbc->iv[i] ^ cbc->key[i]; */
    /*     else */
    /*         cbc->plaintext[i] = cbc->ciphertext[i] ^ cbc->ciphertext[i-16] ^ cbc->key[i%16]; */
    /* } */
}
