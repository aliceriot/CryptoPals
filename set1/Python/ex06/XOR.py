"""
provides the Singlebyte class, which breaks 
single-byte XOR
"""

from collections import Counter

class Singlebyte(object):
    def __init__(self, chunk):
        self.ctext = chunk
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

