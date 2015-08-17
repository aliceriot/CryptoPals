#Detect single-character XOR

One of the 60-character strings in this file has been encrypted by
single-character XOR.

Find it.

(Your code from #3 should help.)

##The approach

First we need to write some Python to break single bit XOR encryption.
This is defined in XOR.py, which has a class called Singlebyte, which has
everything that is needed.


Then once we have that we 

    - any hex string which has been encrypted (under the single-byte XOR
      scheme) will get at least one key with a good score

Things to test:

    - unencrypted strings will probably get a distribution of scores, with
      a higher mean?
    - encrypted strings will get more 'good' keys? (i.e. keys that aren't
      disqualifed for returning non-ascii)

Going to mainly be adapting the code from task03. We'll change the way we
do scoring, from scoring keys for a single message to scoring the message
for encrypted-ness.

##Message scoring

I'm thinking about a variety of different ways in which we can do message
scoring. Some ideas:

    - compare number of keys with score = -1.0 (non ascii, disqualified) 
    - lowest summmed keyscore (for non-rejected keys)
    - ??? probably more options?

Anyway, I'm going to need a lot of the code from task03. I'm going to call the
two scoring options (above) method 1 and method 2, I'm going to write number
2 first.

###Method 2

It does return values! I need to build something to read in the file, loop
through, and return an array of values with method2.

###File load

Trying to read the file in and save each line as a string, with a pointer
of arrays. Always fun to play with files in C...
