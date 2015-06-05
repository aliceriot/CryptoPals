#define MAXLINE 1000

int charCount(char string[], int counts[]);
void countsToFrequency(int totalChars, float frequencies[], int counts[]);
int hexArrayToByteArray(char string[], int byteArray[]);
unsigned int hexToBits(char hex);
float frequencyScore(float frequencies[]);
int findKey(char ciphertext[]);
float testKey(unsigned int ciphertext[], unsigned int key, unsigned int numBytes);
void xorByteArray(int key, int numBytes, int byteArray[], char outArray[]);
