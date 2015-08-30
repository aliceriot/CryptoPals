#Detect AES-ECB

OK for exercise 08 we want to detect which of some 200-odd ciphertexts
(well, hex strings) has been encrypted with AES in ECB mode. Great!

Wait, what's ECB mode, anyway?

##Electronic Codebook mode

ECB is a particular way of using a block cipher to encrypt a message.
Essentially, we devide the message (plaintext) into identically sizes
blocks, and then we encrypt each block by performing whatever the
encryption operation is. This looks like this (thanks wikipedia!):



![](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e6/ECB_decryption.svg/1202px-ECB_decryption.svg.png)

So any block cipher can be used in ECB mode. Great! How flexible! Chopping
the message up into 
