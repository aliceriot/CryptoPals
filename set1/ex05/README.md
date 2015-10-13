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
wrap around again to `key[0]`. This gives us a repeating key, where each
`len(key)` sized block will be encrypted with the whole key.

Once we've encrypted the character it is appended to a bytearray, which we
stick in `self.ciphertext` by doing `binascii.hexlify(bytes)`. `hexlify`
takes a bytearray (or bytes object) as an argument and returns
a hexadecimal representation of this array. Then we can quickly do:

```Python
''.join(map(chr, binascii.hexlify(bytes)))
```

To get a nice printable string (also suitable for comparing string
equality with the desired result). 

Great! Then all we do in order to encrypt the message is:

```Python
repeat = Repeat("message", "key")
repeat.encrypt()
print(repeat.ciphertext)
```

Woo! It totally gets the right answer too! I had a little confusion about
whether there was a newline included in the cleartext - I could tell the
cipher was working correctly because the first half or so of the
ciphertext matched the correct answer. Turns out there's no newline!
