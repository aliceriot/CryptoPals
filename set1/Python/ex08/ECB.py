import binascii
from collections import Counter

class ECBDetector(object):
    def __init__(self, ciphertext):
        self.ciphertext = binascii.unhexlify(ciphertext)
        self.score = 0

    def score(self):
        """
        counts the number of identical blocks
        in the ciphertext
        """
        chunked = chunks(self.ciphertext, 16)
        counts = Counter(chunked)
        score = 0
        for count in counts.values():
            if count > 1:
                total += count
        self.score = score


    def chunks(l, n):
        return [l[i:i+n] for i in range(0, len(l), n)]

