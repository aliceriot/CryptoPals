#include <stdio.h>
#include "oracle.h"

int main()
{
    unsigned char key[16];
    random_aes_key(16, key);

}
