#Exercise 10

For this problem we want to implement a different block cipher - CBC. CBC
is Cipher Block Chaining. It's a mode that avoids one of the main problems
with the simpler block cipher mode we used earlier (ECB), which is that
identical blocks in the plaintext are also identical in the ciphertext.
CBC gets around that by XORing each plaintext block with the previous
ciphertext block before encryption. We XOR the first block in the
plaintext with a starter '0th' block called an initialization vector.

Here's what Wikipedia has to say:

![](https://upload.wikimedia.org/wikipedia/commons/thumb/2/2a/CBC_decryption.svg/601px-CBC_decryption.svg.png)

Cool.

##What do we need to do?

We have a file (`10.txt`) which we can read once we perform CBC with the
initialization vector `\x00\x00\x00` and the phrase `YELLOW SUBMARINE`.
We'll do the actual decryption with AES-128 in ECB mode, and our own code
will handle building CBC mode on top of that.
