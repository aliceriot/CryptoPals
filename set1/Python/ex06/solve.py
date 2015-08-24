#!/usr/bin/python3

from base64 import b64decode
from keysieve import Keysieve
from blocks import Blocks
from XOR import Singlebyte
from decrypt import Decrypt

"""this file actually solves the problem"""

with open("./ex06.txt") as f:
    ciphertext = b64decode(''.join([l.strip() for l in f.readlines()]))

keys = Keysieve(ciphertext, 2, 40)

#create blocks for the 4 best scoring keysize (5, 3, 2, 13)
blocks = Blocks(ciphertext, [x[0] for x in keys.sizes[:4]])

#do Singlebyte on the blocks
for k in blocks.keysizes:
    key = bytearray()
    for b in blocks.blocks[k]:
        temp = Singlebyte(b)
        if {} != temp.keys:
            key.append(min(temp.keys, key=lambda x: temp.keys[x]))
    if key != bytearray():
        print("here!")
        decrypt = Decrypt(ciphertext, key)
        print(decrypt.plaintext)
