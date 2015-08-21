from hamming import distance

class Keysieve(object):
    def __init__(self, ciphertext):
        self.keys = {(keysize, 0) for keysize in range(2,41)}
        self.ciphertext = bytearray(ciphertext)
