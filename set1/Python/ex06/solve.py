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


