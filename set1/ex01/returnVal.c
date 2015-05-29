
char returnVal(int num)
{
    if (num == 63)
        return '/';
    else if (num == 62)
        return '+';
    else if (num > 51)
        return num + 48;
    else if (num > 25)
        return num + 71;
    else
        return num + 65;
}





