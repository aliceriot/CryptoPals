class Singlebyte(object):
    def __init__(self, hexstring):
        self.hexstring = hexstring
        self.bytestring = bytearray.fromhex(hexstring)
        self.onlyascii = True

    def ahelp(self, n):
        "returns true if n is a valid ascii character"
        if n > 31 and n < 127:
            return True
        return False

    def otheridea(self):
        "only those which never fail to produce ascii"
        potk = list(range(256))
        for b in self.bytestring:
            temp = list(filter(lambda x: self.ahelp(x ^ b), potk))
            potk = temp
        return potk

def utility(keys, hexstring):
    for i in keys:
        print(''.join(list(map(chr, map(lambda x: x ^ i, hexstring)))))






