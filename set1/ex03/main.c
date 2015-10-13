#include <stdio.h>
#include <string.h>
#include "xor.h"

void main()
{
    // input string (from Matasano)
    char teststring[] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
		char teststring2[] = "32e902193219033c58191302441a5c1b584825ea140c290927aaea53e23c";
		char teststring3[] = "0a3d1309e4384c0eed383846545a035a41ee1771513b090a031e15f45159";
		char teststring4[] = "2e4c2e373b434b0d0b1b340c300e4b195614130ea03c234c292e14530c46";
		char teststring5[] = "3d191107251100ee2e4125405a44174f061e0e1e5959e606530e06ed245e";

    // byte array, number of bytes, iterator
    int byteArray[MAXLINE]; int numBytes; int i;
    numBytes = hexArrayToByteArray(teststring5, byteArray);
    
    // find good keys (score < 0.06)
    int numKeys;
    int possibleKeys[256];
    numKeys = findKey(teststring5, possibleKeys);

    // loop through keys, print out poss. cleartext (along with score)
    char testKeyArray[MAXLINE];
    float score;


    for (i = 0; i < numKeys; i++) {
        xorByteArray(possibleKeys[i], numBytes, byteArray, testKeyArray);
        score = testKey(byteArray, possibleKeys[i], numBytes);
        printf("Key: %d \t Score: %f \t Message: %s\n", possibleKeys[i], score, testKeyArray);
    }
}
    
    


