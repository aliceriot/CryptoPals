#include "matasano.h"
#include <glib.h>

int main()
{
    printf("got down here");
    const gchar *encoded_ciphertext = getenv("ciphertext");
    guchar *decoded_ciphertext;
    gsize decoded_length;


    if (encoded_ciphertext == 0) {
        printf("error loading ciphertext\n");
        return 1;
    }

    decoded_ciphertext = g_base64_decode(encoded_ciphertext, &decoded_length);

    printf("got down here");

    cbc_cipher *cbc = malloc(sizeof (cbc_cipher));
    cbc->iv = (unsigned char) getenv("iv");
    cbc->key = getenv("key");

    if (cbc->iv == 0 || cbc->key == 0) {
        printf("error initializing struct\n");
        return 1;
    }


    printf("got down here");
    cbc->ciphertext = decoded_ciphertext;
    unsigned char plaintext[decoded_length];
    cbc->plaintext = plaintext;
    cbc->input_length = decoded_length;


    cbc_decrypt(cbc);

    printf("%s\n", cbc->plaintext);

    free(cbc);
    g_free(decoded_ciphertext);
}
