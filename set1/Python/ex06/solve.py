#!/usr/bin/python3

from keysieve import Keysieve
from blocks import Blocks

"""this file actually solves the problem"""

with open("./ex06.txt") as f:
    ciphertext = ''.join([l.strip() for l in f.readlines()])

keys = Keysieve(ciphertext, 2, 40)

blocks = Blocks(ciphertext, [x[0] for x in keys.sizes])
