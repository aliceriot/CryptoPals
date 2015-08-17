
class Repeat(object):
    def __init__(self, cleartext, key):
        self.cleartext = cleartext
        self.key = key
        self.ciphertext = ""

    def encrypt(self):
        bytesbytes = bytearray()
        for i in enumerate(cleartext):
            bytesbytes.append(ord(i[1]) ^ ord(key[i % 3]))



