#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hexConvert.h"

// a simple function to take a hex value and return an int
// needs a couple of helper functions

int mypow(int num, int power)
{
    int output = 1;
    int i;

    if (power == 0)
        return output;
    else if (power == 1)
        return num;
    else if (power > 1) {
        for (i = power; i >= 1; i--) {
            output = output * num;
        }
        return output;
    }
}

int returnNum(char c)
{
    char upper = toupper(c);
    switch (upper) {
        case '0':
            return 0;
            break;
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        case 'A':
            return 10;
            break;
        case 'B':
            return 11;
            break;
        case 'C':
            return 12;
            break;
        case 'D':
            return 13;
            break;
        case 'E':
            return 14;
            break;
        case 'F':
            return 15;
            break;
        default:
            return 0;
            break;
    }
}

int hexToInt(char hex[], int len)
{
    int output = 0;
    int i;
    char revhex[MAXLINE];
    char subhex[MAXLINE];

    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
        for (i = 2; i < len; i++) {
            subhex[i-2] = hex[i];
            reverse(subhex,revhex,len);
            len -= 2;
        }
    }
    else
        reverse(hex,revhex,len);

    for (i=0; i<len; i++) {
        output += returnNum((char)revhex[i]) * mypow(16,i);
    }
    return output;
}

