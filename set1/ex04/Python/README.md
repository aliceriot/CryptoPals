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

Great! So that excludes a lot of possible keys, and it will give us a short
list of potential cleartexts. Then we need to narrow those down! This part is
in `hexstrings.py`. 

We read in the file and strip off newline characters. Then we're going to loop
through each line, and add the potential cleartexts we get from the Singlebyte
class to an array. Before we add them, however, we do a weird thing: we map
called the Word() constructor (from textblob, a NLP library for Python, and try
to get a definition for each word. Then we use a filter to remove the empty
lists (for words with no definition), and then finally, if our string had real
words in it, we add it to an array called goodstring.

Great! This gives us an answer, hooray!




