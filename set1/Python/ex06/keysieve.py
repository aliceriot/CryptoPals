from hamming import distance

class Keysieve(object):
    def __init__(self, ciphertext, minkey, maxkey):
        self.sizes = {keysize: 0 for keysize in range(minkey, maxkey+1)}
        self.ctext = bytearray(ciphertext, 'ascii')
        self.sieve()

    def sieve(self):
        for s in self.sizes.keys():
            self.sizes[s] = distance(self.ctext[0:s], self.ctext[s:2*s])/s

