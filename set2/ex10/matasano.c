#include "matasano.h"
#include <glib.h>

int main()
{
    const gchar *encoded_ciphertext = getenv("ciphertext");
    guchar *decoded_ciphertext;
    gsize decoded_length;

    decoded_ciphertext = g_base64_decode(encoded_ciphertext, &decoded_length);

    size_t i;
    for (i=0; i < decoded_length; i++) {
        printf("%d\t", decoded_ciphertext[i]);
    }

    printf("\n\nlength: %d\n", i);

    cbc_cipher *cbc = malloc(sizeof (cbc_cipher));
    cbc->iv = getenv("iv");
    cbc->key = getenv("key");
    cbc->ciphertext = decoded_ciphertext;
    unsigned char plaintext[decoded_length];
    cbc->plaintext = plaintext;
    cbc->input_length = decoded_length;

    cbc_decrypt(cbc);

    printf("%s\n", cbc->plaintext);

    /* for (size_t i = 0; i < strlen(cbc->plaintext); i++) */
    /*     printf("%d\t", cbc->plaintext[i]); */
    /* g_free(decoded_ciphertext); */
    /* free(cbc); */
}
