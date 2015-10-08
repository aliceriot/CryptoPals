#!/usr/bin/python3

from base64 import b64decode
from keysieve import Keysieve
from blocks import Blocks
from XOR import Singlebyte
from decrypt import Decrypt

"""this file actually solves the problem"""

# read file into bytearray
with open("./ex06.txt") as f:
    ciphertext = b64decode(''.join([l.strip() for l in f.readlines()]))

# keysieve finds probable keysizes (using hamming distance)
keysieve = Keysieve(ciphertext, 2, 40)
keysize = keysieve.scores[0][0]

# create blocks for the best keysize
blocks = Blocks(ciphertext, keysize)

# generate the key
key = bytearray()
for block in blocks.blocks:
    temp = Singlebyte(block)
    key.append(temp.bestkey[0])

# decrypt ciphertext and print
decrypt = Decrypt(ciphertext, key)
print("The key was: {}".format(''.join(map(chr, key))))
print("Plaintext:")
print(decrypt.plaintext)
