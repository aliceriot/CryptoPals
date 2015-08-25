from XOR import Singlebyte
from decrypt import Decrypt

with open('../ex04/hex.txt') as f:
    hexstrings = [bytearray.fromhex(x.strip()) for x in f.readlines()]

possible = []

for hexstring in hexstrings:
    temp = Singlebyte(hexstring)
    decrypt = Decrypt(hexstring, [temp.bestkey])
    possible.append(decrypt.plaintext)


with open('./test.txt', 'w') as f:
    for pos in possible:
        f.write(pos)
