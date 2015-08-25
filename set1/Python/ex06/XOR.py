from collections import Counter

class Singlebyte(object):
    def __init__(self, chunk):
        self.bstr = chunk
        self.results = []
        self.keyscore()
        print(chunk)
        self.bestkey = max(self.results, key = lambda x: x[0])[1]

    def keyscore_old(self):
        """
        get the key scores (number of ascii / len(chunk))
        for all keys, add (score, plaintext) to self.results
        """
        for key in range(256):
            plain = [chr(c ^ key) for c in self.bstr]
            score = list(filter(lambda x: 'a'<=x<='z' or 'A'<=x<='Z', plain))
            self.results.append((float(len(score)) / len(plain), 
                key, ''.join(plain)))

    def keyscore(self):
        common = 'ETAONRISHDL'
        for key in range(256):
            plain = [chr(c^key) for c in self.bstr]
            spaces = plain.count(' ')
            upper = sum(plain.count(c) for c in common)
            lower = sum(plain.count(c) for c in common.lower())
            self.results.append((spaces + upper + lower, key))


            

