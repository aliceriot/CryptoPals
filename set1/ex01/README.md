This convert a sequence from hex to Base64. I'm doing this in C.

Input string:
    
    49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d

This is what the challenge gives us. Apparently this will produce:

    SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t

ehh?

printBinary is a helper function that prints out a binary representation of an
integer.
