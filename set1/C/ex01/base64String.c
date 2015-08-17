#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hexConvert.h"

void base64String(char output[], int input)
{

    int scratch, i, j = 0;
    int mask = 63; // 111111

    for (i = 18; i > 0; i -= 6) {
        scratch = (input >> i) & mask;
        output[j++] = returnVal(scratch);
    }
}


