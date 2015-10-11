#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <openssl/ssl.h>

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

    size_t i;
    int outlen;
    unsigned char buffer[cbc->input_length];

    // openssl 
    EVP_CIPHER_CTX ctx;
    EVP_CIPHER_CTX_init(&ctx);
    EVP_DecryptInit_ex(&ctx, EVP_aes_128_ecb(), NULL, cbc->key, NULL);

    EVP_DecryptUpdate(&ctx, buffer, &outlen, cbc->ciphertext, cbc->input_length);

    for (i = 0; i < cbc->input_length; i++) {
        if (i < 16) {
            cbc->plaintext[i] = buffer[i] ^ cbc->iv[i];
        }
        else {
            cbc->plaintext[i] = buffer[i] ^ cbc->ciphertext[i -16];
        }
    }
}
