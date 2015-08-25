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
            second = self.ctext[ksize:2*ksize]
            self.scores.append((ksize, distance(first, second) / ksize))


    def trialsieve(self):
        for ksize in self.keys:
            c = [self.ctext[:ksize]]
            sizerange = [ksize+i for i in range(int(len(self.ctext) / ksize))]
            c += [self.ctext[i:ksize+i] for i in sizerange]
            even = [i[1] for i in enumerate(c) if i[0] % 2 == 0]
            odd = [i[1] for i in enumerate(c) if i[0] % 2 != 0]
            score = avg([distance(z[0], z[1])/ksize for z in zip(even, odd)])
            self.scores.append((ksize, score))
