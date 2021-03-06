class HexString:
    def __init__(self, hex):
        self.hexString = hex
        self.bytes = bytearray.fromhex(hex)
        self.counts = {}
        self.score = 0
        self.frequencies = []
        self.byteCounts()
        self.freqScore()

    def byteCounts(self):
        for i in self.bytes:
            if i in self.counts:
                self.counts[i] += 1
            else:
                self.counts[i] = 1

    def freqScore(self):
        english = [0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, \
                0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, \
                0.06749, 0.07507, 0.01929, 0.00095, 0.05987,0.06327, 0.09056, \
                0.02758, 0.00978, 0.02361, 0.00150, 0.01974, 0.00074]
        english.sort()
        english.reverse()

        self.frequencies = [(lambda x: x/len(self.counts))(i) for i in self.counts.values()]
        self.frequencies.sort()
        self.frequencies.reverse()

        for i in range(15):
            self.score += (lambda x: (x - english[i])**2)(self.frequencies[i])




        # can use ord(char) to get the ascii value, which can use to look up
        # the frequency in the above array
