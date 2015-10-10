#include "matasano.h"

int main()
{
    cbc_cipher *cbc = malloc(sizeof (cbc_cipher));

    cbc->iv = getenv("iv");
    cbc->key = getenv("key");
    cbc->ciphertext = getenv("ciphertext");

    char plaintext[strlen(cbc->ciphertext)];
    cbc->plaintext = plaintext;

    cbc_decrypt(cbc);

    /* printf("%s\n", cbc->plaintext); */

    for (size_t i = 0; i < strlen(cbc->plaintext); i++)
        printf("%d\t", cbc->plaintext[i]);
}
