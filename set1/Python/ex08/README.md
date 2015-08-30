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

