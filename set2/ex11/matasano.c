#include <stdio.h>
#include "oracle.h"

int main()
{
    unsigned char *plaintext = "just a test whoooasdfasdf";
    unsigned char ciphertext[strlen(plaintext)];

    random_encryption(plaintext, ciphertext);

    for (int i =0; i < strlen(ciphertext); i++) {
        printf("%x\t%x\n", plaintext[i], ciphertext[i]);
    }
}
