
class Decrypt(object):
    """
    take ciphertext and keyarray, perform
    decryption with it
    """
    def __init__(self, ciphertext, keyarray):
        self.ctext = ciphertext
        self.keys = keyarray
        self.plaintext = ''
        self.decrypt()

    def decrypt(self):
        temp = []
        for i in enumerate(self.ctext):
            temp.append(i[1] ^ self.keys[i[0] % len(self.keys)])
        self.plaintext = ''.join(map(chr, temp))
