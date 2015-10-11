#include "matasano.h"
#include <glib.h>

int main()
{
    const gchar *encoded_ciphertext = getenv("ciphertext");
    guchar *decoded_ciphertext;
    gsize decoded_length;

    if (encoded_ciphertext == 0) {
        printf("error loading ciphertext\n");
        return 1;
    }

    decoded_ciphertext = g_base64_decode(encoded_ciphertext, &decoded_length);

    cbc_cipher *cbc = malloc(sizeof (cbc_cipher));

    /* char *iv = getenv("iv"); */ 
    /* memcpy(cbc->iv, iv, 16); */
    cbc->iv = getenv("iv");

    /* char *key = getenv("iv"); *1/ */
    /* memcpy(cbc->key, key, 16); */
    cbc->key = getenv("key");

    if (cbc->iv == 0 || cbc->key == 0) {
        printf("error initializing struct\n");
        return 1;
    }

    cbc->ciphertext = decoded_ciphertext;
    unsigned char plaintext[decoded_length];
    cbc->plaintext = plaintext;
    cbc->input_length = decoded_length;
    cbc_decrypt(cbc);

    printf("plaintext:\n");
    printf("%s\n", cbc->plaintext);

    free(cbc);
    g_free(decoded_ciphertext);

}
