#include <stdio.h>

// a simple function to print out an integer in binary

void printBinary(int x)
{
    int i;
    int print[64];

    for (i = 0; i < 64; i++) {
        if (x & 1)
            print[i] = 1;
        else
            print[i] = 0;
        x >>= 1;
    }

    for (i = 63; i >= 0; i--) {
        if (print[i] == 1)
            putchar('1');
        else if (print[i] == 0)
            putchar('0');
    }
    putchar('\n');
}

main()
{
    int c;
    c = getchar();
    printBinary(c - '0');
    printBinary(10);
}
