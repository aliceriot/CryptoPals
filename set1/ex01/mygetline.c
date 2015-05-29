#include<stdio.h>

int mygetline(char s[], int lim)
{
    int c,i;

    for (i=0; (c=getchar()) != EOF && c!='\n' && i < lim -1; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return --i;
}
