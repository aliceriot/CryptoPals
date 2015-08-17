import sys
from hexstring import HexString
from ctypes import cdll

if (len(sys.argv) > 1):
    filename = sys.argv[1]
else:
    filename = "../hex.txt"

with open(filename, 'r') as myfile:
    raw = [line.strip() for line in myfile]

hexArray = [HexString(i) for i in raw]

goodones = []
for i in hexArray:
    if i.score < 0.002:
        goodones.append(i)

scores = []
for i in hexArray:
    scores.append(i.score)
    





#lib = cdll.LoadLibrary("modules")
