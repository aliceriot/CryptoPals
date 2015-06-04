#include <stdio.h>
#include "xor.h"

void xorByteArray(int test, int numBytes, int byteArray[], int outArray[])
{
    int i;
    for (i = 0; i < numBytes; i++)
        outArray[i] = test ^ byteArray[i];
}
    


