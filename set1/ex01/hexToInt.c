#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hexConvert.h"


int hexToInt(char one, char two)
{

    int numOne = returnNum(one);
    int numTwo = returnNum(two);

    return numTwo + (numOne * 16);
}
