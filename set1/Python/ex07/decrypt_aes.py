from Crypto.Cipher import AES
from Crypto import Random
from base64 import b64decode

with open('./ex07.txt') as f:
    ciphertext = b64decode(''.join([x.strip() for x in f.readlines()]))

key = b'YELLOW SUBMARINE'

cipher = AES.new(key)

print(''.join(map(chr, cipher.decrypt(ciphertext))))
