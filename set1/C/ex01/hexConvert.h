#define MAXLINE 10000

int returnNum(char c);
int reverse(char forward[], char backward[], int len);
//int mypower(int num, int power);
int hexToInt(char one, char two);
int mygetline(char s[], int lim);
int convertListToInt(char hex[], int intVals[]);
int convertListToBase64(int intVals[], char base64[]);
int intToBase64(int intVals[], char base64[], int numInts);
char returnVal(int num);
void base64String(char out[], int in);
