class Singlebyte(object):
    def __init__(self, hexstring):
        self.hexstring = hexstring
        self.bytestring = bytearray.fromhex(hexstring)
        self.onlyascii = True
        self.potk = list(range(256))
        self.strings = []
        self.keyexclude()
        self.stringexclude()

    def ahelp(self, n):
        "returns true if n is a valid ascii character"
        if n > 31 and n < 127:
            return True
        elif n == 10:
            return True
        return False

    def keyexclude(self):
        "only those which never fail to produce ascii"
        for b in self.bytestring:
            temp = list(filter(lambda x: self.ahelp(x ^ b), self.potk))
            self.potk = temp

    def stringexclude(self):
        "we assume there's a space"
        pos = []
        for k in self.potk:
            pos.append(''.join(list(map(chr, map(lambda x: x ^ k, self.bytestring)))))
        self.strings = list(filter(lambda x: ' ' in x, pos))

