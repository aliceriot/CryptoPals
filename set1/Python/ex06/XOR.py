from collections import Counter

class Singlebyte(object):
    def __init__(self, chunk):
        self.bstr = chunk
        self.results = []
        self.keyscore()
        self.bestkey = max(results, key = lambda x: x[0])

    def keyscore(self):
        """
        get the key scores (number of ascii / len(chunk))
        for all keys, add (score, plaintext) to self.results
        """
        for key in range(256):
            plain = [chr(c ^ key) for c in chunk]
            score = filter(lambda x: 'a'<=x<='z' or 'A'<=x<='Z', plain)
            self.results.append((float(len(score)) / len(plain)), ''.join(plain))


