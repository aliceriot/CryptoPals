#Detect single-character XOR

One of the 60-character strings in this file has been encrypted by
single-character XOR.

Find it.

(Your code from #3 should help.)

##The approach

First we need to write some Python to break single bit XOR encryption.
This is defined in XOR.py, which has a class called Singlebyte, which has
everything that is needed.

The Singlebyte class starts it off - it excludes as possible keys anything
that, when XORed with any byte in the bytestring, produces a non-ascii
character. We also make the assumption that all message cleartexts will contain
at least one space character.
