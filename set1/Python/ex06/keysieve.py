from hamming import distance
from numpy import average as avg

class Keysieve(object):
    def __init__(self, ciphertext, minkey, maxkey):
        self.scores = []
        self.keys = range(minkey, maxkey+1)
        self.ctext = ciphertext
        self.sieve()

    def sieve(self):
        for ksize in self.keys:
            first = self.ctext[:ksize]
            rest = [self.ctext[i*ksize:(i+1)*ksize] for i in range(10)]
            scores = [distance(first, i)/ksize for i in rest]
            self.scores.append((ksize, avg(scores)))
        self.scores.sort(key = lambda x: x[1])
