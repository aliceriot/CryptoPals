import binascii

class Repeat(object):
    def __init__(self, cleartext, key):
        self.cleartext = cleartext
        self.key = list(map(ord, key))
        self.ciphertext = ""

    def encrypt(self):
        bytesbytes = bytearray()
        for i in enumerate(self.cleartext):
            bytesbytes.append(ord(i[1]) ^ self.key[i[0] % len(self.key)])
        self.ciphertext = binascii.hexlify(bytesbytes)


repeat = Repeat("Burning 'em, if you ain't quick and nimble I go crazy when I hear a cymbal", "ICE")
repeat.encrypt()

correct_answer = "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f"

print(''.join(list(map(chr, repeat.ciphertext))))
print(correct_answer)
