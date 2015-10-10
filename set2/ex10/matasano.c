#include "matasano.h"
#include <glib.h>

int main()
{
    cbc_cipher *cbc = malloc(sizeof (cbc_cipher));

    unsigned char *base_64 = getenv("ciphetext");
    guchar *decoded_ciphertext;
    size_t *decoded_length;
    decoded_ciphertext = g_base64_decode(base_64, decoded_length);

    cbc->iv = getenv("iv");
    cbc->key = getenv("key");
    cbc->ciphertext = decoded_ciphertext;

    char plaintext[strlen(cbc->ciphertext)];
    cbc->plaintext = plaintext;

    cbc_decrypt(cbc);

    /* printf("%s\n", cbc->plaintext); */

    for (size_t i = 0; i < strlen(cbc->plaintext); i++)
        printf("%d\t", cbc->plaintext[i]);
}
