import sys
from hexstring import HexString

if (len(sys.argv) > 1):
    filename = sys.argv[1]
else:
    filename = "../hex.txt"

with open(filename, 'r') as myfile:
    raw = [line.strip() for line in myfile]


hexArray = [HexString(i) for i in raw]

