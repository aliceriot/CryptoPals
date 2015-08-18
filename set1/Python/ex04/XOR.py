"""
Provides a class (Singlebyte) for solving single-byte
XOR for a hexadecimal string. Usage:

    decrypt = Singlebyte("deadbeef")

Possible plaintexts are in decrypt.strings.
"""

class Singlebyte(object):
    """Singlebyte class, solves random single-byte XOR cipher"""
    def __init__(self, hexstring):
        self.hexstring = hexstring
        self.bytestring = bytearray.fromhex(hexstring)
        self.onlyascii = True
        self.potk = list(range(256))
        self.strings = []
        self.keyexclude()
        self.stringexclude()

    def ahelp(self, key):
        """
        Returns true if key is a valid ascii character
        or a keyewline (10).
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
        for b in self.bytestring:
            temp = list(filter(lambda x: self.ahelp(x ^ b), self.potk))
            self.potk = temp

    def stringexclude(self):
        """
        Exclude all strings that do not contain spaces
        (explicit assumption).
        """
        pos = []
        for k in self.potk:
            pos.append(''.join(list(map(chr, map(lambda x: x ^ k, self.bytestring)))))
        self.strings = list(filter(lambda x: ' ' in x, pos))
