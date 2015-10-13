#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <openssl/ssl.h>

// CBC/ECB encryption oracle for Matasano problem 11

void random_bytes(int numbytes, unsigned char *output)
{
    srand(time(NULL));

    for (size_t i=0; i < numbytes; i++) {
        output[i] = rand() % 256;
    }
}


void random_encryption(unsigned char *plaintext, unsigned char *ciphertext)
{

    EVP_CIPHER_CTX ctx;
    EVP_CIPHER_CTX_init(&ctx);
    int outlength;

    srand(time(NULL));
    int decrypt_switch = rand() % 2;
    char key[16];
    random_bytes(16,key);

    if (decrypt_switch == 1) {
        char iv[16];
        random_bytes(16, iv);
        EVP_EncryptInit_ex(&ctx, EVP_aes_128_cbc(), NULL, key, iv);
        EVP_EncryptUpdate(&ctx, ciphertext, &outlength, plaintext, strlen(plaintext));
    }
    else {
        EVP_EncryptInit_ex(&ctx, EVP_aes_128_ecb(), NULL, key, NULL);
        EVP_EncryptUpdate(&ctx, ciphertext, &outlength, plaintext, strlen(plaintext));
    }
}

