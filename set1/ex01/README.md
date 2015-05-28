This convert a sequence from hex to Base64. I'm doing this in C.

Input string:
    
    49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d

This is what the challenge gives us. Apparently this will produce:

    SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t

ehh?

printBinary is a helper function that prints out a binary representation of an
integer.

So how do we do it? Well, basically in the hex string every 2 characters
described the state of one byte (a number 0-255). So what we want to do
(first) is loop through that string, and convert every 2 numbers into an
integer (which we'll store in an array).

Then we take sets of three integers, and that becomes 4 characters in
Base64. Nice!

todo:

    - write int -> base64 converter
    - write a function to chain converters
    - makefile!
