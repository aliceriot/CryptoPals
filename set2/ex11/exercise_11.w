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

@ Great! So if we want to actually do some random encryption we're going to
need that random key. We included above the headers for OpenSSL, so we can
use a (somewhat) friendly interface to that library of cryptographic primatives.

Basically, we're going to generate a random key, randomly pick either ECB or CBC
mode to encrypt our plaintext, and write the encrypted output to a pointer we
pass in.

@c
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


@ This is a placeholder `main' function for now:

@c
int main()
{
    unsigned char *plaintext = "just a test whoooasdfasdf";
    unsigned char ciphertext[strlen(plaintext)];

    random_encryption(plaintext, ciphertext);

    for (int i =0; i < strlen(ciphertext); i++) {
        printf("%x\t%x\n", plaintext[i], ciphertext[i]);
    }
}
