#Repeating-key XOR

OK, this is a different sort of thing. We're going to implement
a repeating-key XOR cipher. We want to encrypt:

    Burning 'em, if you ain't quick and nimble
    I go crazy when I hear a cymbal

with the key `ICE`. So what this means is that we iterate through `ICE` using
`I` for the first byte of the message, `C` for the second, and so on. Great!

More Python!
