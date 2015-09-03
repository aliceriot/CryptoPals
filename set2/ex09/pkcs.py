import binascii

class Pkcs7(object):
    def __init__(self, plaintext, padded_length):
        self.plaintext = bytearray(plaintext, 'ascii')
        self.padded_length = padded_length

    def pad(self):
        if self.padded_length < len(self.plaintext):
            raise ValueError("bad padded length for input plaintext")
        diff = self.padded_length - len(self.plaintext)
        while len(self.plaintext) < self.padded_length:
            self.plaintext.append(diff)


        
