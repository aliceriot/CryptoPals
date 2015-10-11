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

Cool. If you want to run it there's a little shell script that builds the
program and sets the environmental variables correctly. You'll need
`pkg-config`, `cmake`, and headers for OpenSSL and glib-2.0, then do:

```
./solve.sh
```

##What do we need to do?

We have a file (`10.txt`) which we can read once we perform CBC with the
initialization vector `\x00\x00\x00` and the phrase `YELLOW SUBMARINE`.
We'll do the actual decryption with AES-128 in ECB mode, and our own code
will handle building CBC mode on top of that.

##How does it work?

The thing that ended up working for me was using AES-128 in ECB mode on
the whole input, and then looping through the input to XOR each character
with the right character in the ciphertext. There's a struct and
a function in `matasano.h` which take care of this together.

I had fun with this one trying to write C code which uses libraries more
smoothly - I used glib for decoding b64 and OpenSSL for AES.
