#Single-byte XOR cipher

The hex encoded string:

    1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736

has been XOR'd against a single character. Find the key, decrypt the message.

You can do this by hand. But don't: write code to do it for you.

How? Devise some method for "scoring" a piece of English plaintext. Character
frequency is a good metric. Evaluate each output and choose the one with the
best score.

Ok, so this is how I'm going to do this:

It's not that hard to check all 0-255. So we XOR again those numbers, and then
we'll take each message and claculate the character frequency, and score
it based on how different it is from normal English character frequency.

Not sure the best way to calculate the difference though...

Well, first off we're going to need a library for doing a couple things.

xor.h
    - function definitions, MAXLINE?

charcount.c:
    - int charCount(char string[], int counts[]);
        - takes a string and an array for integers, and puts the count of
          each letter into the counts array
    - void countsToFrequency(int totalChars, float frequencies[], int
      counts[]);
        - converts raw counts into frequencies
    - float frequencyCompare(float frequencies);
        - takes an array of frequencies and returns the score of our
          comparison to English character frequency

hexfunctions.c:
    - int hexToBits(char hex);
        - from before
    - int hexArrayToByteArray(char hex[], int bytes[]);
        - takes our hex string, turns it into bytes
        - I think once I have that I don't actually need a bytetostring?

xorcipher.c
    - void xorByteArray(int test, int numBytes, int byteArray[], int
      outArray[])
        - just returns intput ^ operand

