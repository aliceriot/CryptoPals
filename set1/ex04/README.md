#Detect single-character XOR

One of the 60-character strings in this file has been encrypted by single-character XOR.

Find it.

(Your code from #3 should help.)

##My approach

Ok, so let's make some assumptions:

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

