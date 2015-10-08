
from base64 import b64decode

with open("./ex06.txt") as f:
    ciphertext = b64decode(''.join([l.strip() for l in f.readlines()]))

def distance(s1, s2):
    return sum(bin(x^y).count('1') for x,y in zip(s1,s2))

from statistics import mean

class Keysieve(object):
    def __init__(self, ciphertext, minkey, maxkey):
        self.scores = []
        self.keys = range(minkey, maxkey + 1)
        self.ctext = ciphertext
        self.sieve()

    def sieve(self):
        for ksize in self.keys:
            first = self.ctext[:ksize]
            chunks = [self.ctext[i*ksize:(i+1)*ksize] for i in range(10)]
            scores = [distance(first, i)/ksize for i in chunks]
            self.scores.append((ksize, mean(scores)))
        self.scores.sort(key = lambda x: x[1])

keysieve = Keysieve(ciphertext, 2,40)

keysize = keysieve.scores[0][0]

class Blocks(object):
    """takes ciphertext and best keysizes, makes blocks"""
    def __init__(self, ciphertext, keysize):
        self.ciphertext = ciphertext
        self.keysize = keysize
        self.blocks = [[] for i in range(self.keysize)]
        self.blockify()

    def blockify(self):
        for tup in enumerate(self.ciphertext):
            self.blocks[tup[0] % self.keysize].append(tup[1])
        map(bytearray, self.blocks)

blocks = Blocks(ciphertext, keysize)

from collections import Counter

class Singlebyte(object):
    def __init__(self, block):
        self.ctext = block
        self.keys = []
        self.scorekeys()
        self.bestkey = max(self.keys, key = lambda x: x[1])

    def scorekeys(self):
        common = 'etaoinshrd'
        for key in range(256):
            plain = ''.join(map(lambda c: chr(c^key), self.ctext))
            spaces = plain.count(' ')
            upper = sum(plain.count(c) for c in common.upper())
            lower = sum(plain.count(c) for c in common)
            self.keys.append((key, spaces + upper + lower))

key = bytearray()
for block in blocks.blocks:
    temp = Singlebyte(block)
    key.append(temp.bestkey[0])

class Decrypt(object):
    def __init__(self, ciphertext, key):
        self.ctext = ciphertext
        self.key = key
        self.plaintext = ''
        self.decrypt()

    def decrypt(self):
        temp = []
        for i in enumerate(self.ctext):
            temp.append(i[1] ^ self.key[i[0] % len(self.key)])
        self.plaintext = ''.join(map(chr, temp))

decrypt = Decrypt(ciphertext, key)

print("The key was: {}".format(''.join(map(chr, key))))
print("Plaintext:")
print(decrypt.plaintext)