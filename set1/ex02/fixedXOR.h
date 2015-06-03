#define MAXLINE 1000

unsigned int hexToBits(char hex);
void bitArrayFromHex(char hex[], int bitArray[]);
void pairwiseXOR(unsigned int hexOne[], unsigned int hexTwo[], int len, unsigned int out[]);
char bitsToHex(unsigned int x);
void hexFromBitArray(unsigned int bitArray[], int len, char hex[]);
