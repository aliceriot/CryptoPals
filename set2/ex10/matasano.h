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

    unsigned char buffer[16];
    size_t i;
    int outlen;

    // openssl 
    EVP_CIPHER_CTX ctx;
    EVP_CIPHER_CTX_init(&ctx);
    EVP_DecryptInit_ex(&ctx, EVP_aes_128_ecb(), NULL, cbc->key, NULL);

    for (i = 0; i < cbc->input_length; i++) {
        if ((i % 16 == 0) && (i > 0)) {
            // we're at the dividing line between two blocks
            // do the aes and the CBC stuff
            EVP_DecryptUpdate(&ctx, &cbc->plaintext[i-16], &outlen, buffer, 16);
            
            if (i == 16) {
                for (int j=0; j < 16; j++) {
                    cbc->plaintext[j] = cbc->plaintext[j] ^ cbc->iv[j];
                }
            }
            else {
                for (int j = i-16; j < i; j++) {
                    cbc->plaintext[j] = cbc->plaintext[j] ^ cbc->ciphertext[j-16];
                }
            }
        }
        buffer[i%16] = cbc->ciphertext[i];
    }



    // make a buffer
    // decrypt 16 bytes at a type
    // XOR with previous 16 bytes or iv
    // add to growing decrypted ciphertext

}
