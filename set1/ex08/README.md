#Detect AES-ECB

OK for exercise 08 we want to detect which of some 200-odd ciphertexts
(well, hex strings) has been encrypted with AES in ECB mode. Great!

Wait, what's ECB mode, anyway?

##Electronic Codebook mode

ECB is a particular way of using a block cipher to encrypt a message.
Essentially, we devide the message (plaintext) into identically sizes
blocks, and then we encrypt each block by performing whatever the
encryption operation is. This looks like this (thanks wikipedia!):



![](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e6/ECB_decryption.svg/1202px-ECB_decryption.svg.png)

So any block cipher can be used in ECB mode. Great! How flexible! Chopping
the message up into separate blocks, each of which is encrypted
independently, also means that the encryption operation can be
parallelized (since the encryption of any block depends only upon that
block's plaintext).

ECB has a fatal flaw though - this separate encryption means that if your
message plaintext contains two blocks that are identical, then your
ciphertext will also have identical blocks (in the corresponding
positions).

This is not good. This means you're vulnerable to some ciphertext-only
attacks, and in particular we're going to leak information about the
plaintext contents. An attacker could use the pattern of repeated blocks
to gain information about what type of file is being transmitted, or could
even again information about file contents. Yikes!

##How do we detect?

Well, the [problem description](http://cryptopals.com/sets/1/challenges/8/)
gives us a hint that the blocksize is 16. So basically what we're going to do
is look for any ciphertexts in our input file (`ex08.txt`) which have repeated,
16-byte blocks in them. I wrote a class called `ECBDetector` which lets us do
that. Then we can read in the file line-by-line, score the number of repeating
blocks, and print the result. This is what `detect.py` does:

```Python
from ECB import ECBDetector

with open("./ex08.txt") as f:
    hexstrings = [x.strip() for x in f.readlines()]

goodscores = []
for hexstring in hexstrings:
    temp = ECBDetector(hexstring)
    if temp.score > 0:
        goodscores.append((temp.score, hexstring))

score, hexstring = goodscores[0]

print("The best scoring ciphertext:\n{}\nWith {} repeating blocks."\
        .format(hexstring, score))
```

Great! We get just one hexstring out. I think we have to assume this is right,
Matasano doesn't publish specific answers so I'm not sure how to check. Ah
well!
