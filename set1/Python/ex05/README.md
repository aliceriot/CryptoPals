#Repeating-key XOR

OK, this is a different sort of thing. We're going to implement
a repeating-key XOR cipher. We want to encrypt:

    Burning 'em, if you ain't quick and nimble
    I go crazy when I hear a cymbal

with the key `ICE`. So what this means is that we iterate through `ICE` using
`I` for the first byte of the message, `C` for the second, and so on. Great!

More Python!

##Implementation

Everything for this problem is in `repeatkey.py`. We have a class called
Repeat, which takes a `cleartext` and a `key` as arguments to it's
constructor. The key and cleartext are not hardcoded, and this cipher
could be used to encrypt with any length key.

Basically then what we do is build the ciphertext by iterating through the
plain text and, for each character, we encrypt by XORing the `ord` of that
char with the position in the string modulo `len(key)`. So on the first
character its `key[0]`, then `key[1]`, and after the 3rd character we will
wrap around again to `key[0]`. This gives us a repeating key, where 
