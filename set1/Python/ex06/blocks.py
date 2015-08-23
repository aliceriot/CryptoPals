
class Blocks(object):
    """takes ciphertext and best keysizes, makes blocks"""
    def __init__(self, ciphertext, keysizes):
        self.ciphertext = bytearray(ciphertext, 'ascii')
        self.keysizes = keysizes #list
        self.blocks = {k: [] for k in self.keysizes}
        self.blockify()

    def blockify(self):
        for k in self.keysizes:
            for i in range(0, k):
                temp = []
                index = i
                while index < len(self.ciphertext):
                    temp.append(self.ciphertext[index])
                    index += k
                self.blocks[k].append(temp)
                
            
