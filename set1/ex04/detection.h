#define MAXLINE 1000
#define FILEBUF 21000

int charCount(char string[], int counts[]);
void countsToFrequency(int totalChars, float frequencies[], int counts[]);
int hexArrayToByteArray(char string[], int byteArray[]);
unsigned int hexToBits(char hex);
float frequencyScore(float frequencies[]);
int findKey(char ciphertext[], int possibleKeys[]);
float testKey(unsigned int ciphertext[], unsigned int key, unsigned int numBytes);
void xorByteArray(int key, int numBytes, int byteArray[], char outArray[]);
float methodTwo(char ciphertext[]);
int loadFile(char fileLocation[], char *stringArray[]);
int methodTwoLoop(char *stringArray[], int numLines, int goodLines[]);
