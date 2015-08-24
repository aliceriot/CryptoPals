from collections import Counter

class Singlebyte(object):
    def __init__(self, chunk):
        self.bstr = chunk
        self.potk = list(range(256))
        self.keys = {}
        self.keyexclude()
        self.freqrank()

    def ahelp(self, key):
        """
        Returns true if key is a valid ascii character
        or a newline
        """
        if key > 31 and key < 127:
            return True
        elif key == 10:
            return True
        return False

    def keyexclude(self):
        """
        Exclude all keys which XOR to produce non-ascii
        characters.
        """
        for b in self.bstr:
            temp = list(filter(lambda x: self.ahelp(x ^ b), self.potk))
            self.potk = temp

    def freqrank(self):
        """
        Compare potential keys to normal english
        letter frequency. Lowest score is best.
        """
        english = {'a': 8.167, 'b': 1.492, 'c': 2.782, 'd': 4.253,
                'e': 12.702, 'f': 2.228, 'g': 2.015, 'h': 6.094, 
                'i': 6.966, 'j': 0.153, 'k': 0.772, 'l': 4.025, 
                'm': 2.406, 'n': 6.749, 'o': 7.507, 'p': 1.929,
                'q': 0.095, 'r': 5.987, 's': 6.327, 't': 9.056,
                'u': 2.758, 'v': 0.978, 'w': 2.361, 'x': 0.150,
                'y': 1.974, 'z': 0.074}
        for k in self.potk:
            temp = ''.join(map(chr, map(lambda x: x^k, self.bstr)))
            freqs = Counter(temp.lower())
            difference = 0
            for letter in english.keys():
                tempfreq = 100 * (freqs[letter] / len(temp))
                difference += tempfreq - english[letter]
            self.keys[k] = abs(difference)
