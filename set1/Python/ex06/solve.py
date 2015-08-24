#!/usr/bin/python3

from base64 import b64decode
from keysieve import Keysieve
from blocks import Blocks
from XOR import Singlebyte
from decrypt import Decrypt

"""this file actually solves the problem"""

with open("./ex06.txt") as f:
    ciphertext = b64decode(''.join([l.strip() for l in f.readlines()]))

keysieve = Keysieve(ciphertext, 2, 40)

#create blocks for the 4 best scoring keysize (5, 3, 2, 13)
blocks = Blocks(ciphertext, [x[0] for x in keysieve.sizes[:4]])

# #do Singlebyte on the blocks
potentials = []
for k in blocks.keysizes:
    key = bytearray()
    for b in blocks.blocks[k]:
        temp = Singlebyte(b)
        if {} != temp.keys:
            key.append(min(temp.keys, key=lambda x: temp.keys[x]))
    if key != bytearray():
        decrypt = Decrypt(ciphertext, key)
        potentials.append(decrypt.plaintext)

for string in potentials:
    if ' ' in string:
        print(string)