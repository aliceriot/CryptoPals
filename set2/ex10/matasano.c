#include "matasano.h"

int main()
{
    cbc_cipher *cbc = malloc(sizeof (cbc_cipher));

    cbc->iv = getenv("iv");
    cbc->key = getenv("key");
    cbc->plaintext = getenv("plaintext");

    char result[strlen(cbc->plaintext)];
    cbc_encrypt(cbc, result);

    /* printf("%s\n", result); */

    printf("%d\n", strlen(cbc->key));
    printf("%d\n", strlen(cbc->iv));
    printf("%d\n", strlen(cbc->plaintext));
}
