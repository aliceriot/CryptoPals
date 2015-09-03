#Implement PKCS#7 padding

A block cipher transforms a fixed-sized block (usually 8 or 16 bytes) of
plaintext into ciphertext. But we almost never want to transform a single
block; we encrypt irregularly-sized messages.

One way we account for irregularly-sized messages is by padding, creating
a plaintext that is an even multiple of the blocksize. The most popular
padding scheme is called PKCS#7.

So: pad any block to a specific block length, by appending the number of
bytes of padding to the end of the block. For instance,

```
"YELLOW SUBMARINE"
```

```
"YELLOW SUBMARINE\x04\x04\x04\x04"
```

##Solution

I did two quick solutions, one in Ruby and one in Python. They are pretty
similar (perhaps not surprising). Both define a class called Pkcs7 which
can be initialized with a plaintext and a padded length, and both have
a method called `pad` which pads out the plaintext.

Great!
