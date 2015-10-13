
class Blocks(object):
    """takes ciphertext and best keysizes, makes blocks"""
    def __init__(self, ciphertext, keysize):
        self.ciphertext = ciphertext
        self.keysize = keysize
        self.blocks = [[] for i in range(self.keysize)]
        self.blockify()

    def blockify(self):
        for tup in enumerate(self.ciphertext):
            self.blocks[tup[0] % self.keysize].append(tup[1])
        map(bytearray, self.blocks)
