
class Blocks(object):
    """takes ciphertext and best keysizes, makes blocks"""
    def __init__(self, ciphertext, keysizes):
        self.ciphertext = ciphertext
        self.keysizes = [x[0] for x in keysizes]
        self.blocks = {k: [] for k in self.keysizes}
        self.blockify()

    def blockify(self):
        for k in self.keysizes:
            for i in range(0, k):
                temp = bytearray()
                index = i
                while index < len(self.ciphertext):
                    temp.append(self.ciphertext[index])
                    index += k
                self.blocks[k].append(temp)
