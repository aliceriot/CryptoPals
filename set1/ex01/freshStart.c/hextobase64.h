#define MAXLINE 1000

int hexToBits(char hex);
int bitArrayFromHex(char hex[], int bitArray[]);
int byteArrayFromBits(int bitArray[], int byteArray[], int numBits);
char bitsToBase64(unsigned int n);
int bytesToBase64(unsigned int bytes[], char base64[], int numbytes);
