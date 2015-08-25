#!/usr/bin/python3

from XOR import Singlebyte
from decrypt import Decrypt

with open('./../ex04/hex.txt') as f:
    hexstrings = [bytearray.fromhex(x.strip()) for x in f.readlines()]

possible = []

for hexstring in hexstrings:
    temp = Singlebyte(hexstring)
    possible.append((temp.bestkey, hexstring))
    # decrypt = Decrypt(hexstring, [temp.bestkey])
    # possible.append(decrypt.plaintext)

best = max(possible, key = lambda x: x[0][1])
decrypt = Decrypt(best[1], [best[0][0]])
print(decrypt.plaintext)
