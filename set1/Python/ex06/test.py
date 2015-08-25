#!/usr/bin/python3

from XOR import Singlebyte
from decrypt import Decrypt

with open('./../ex04/hex.txt') as f:
    hexstrings = [bytearray.fromhex(x.strip()) for x in f.readlines()]

possible = []

for hexstring in hexstrings:
    temp = Singlebyte(hexstring)
    possible.append((temp.bestkey[0], temp.bestkey[1], hexstring))

best = max(possible, key = lambda x: x[1])
decrypt = Decrypt(best[2], [best[0]])
print(decrypt.plaintext)
