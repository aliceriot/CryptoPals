from hamming import distance

class Keysieve(object):
    def __init__(self, ciphertext, minkey, maxkey):
        self.sizes = []
        self.keys = range(minkey, maxkey+1)
        self.ctext = ciphertext
        self.sieve()

    def sieve(self):
        for s in self.keys:
            self.sizes.append((s, distance(self.ctext[0:s], self.ctext[s:2*s])/s))
        self.sizes.sort(key=lambda s: s[1])

