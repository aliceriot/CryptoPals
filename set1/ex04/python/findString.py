import sys
from hexstring import HexString

filename = sys.argv[1]

with open(filename, 'r') as myfile:
    raw = [line.strip() for line in myfile]


hexArray = [HexString(i) for i in raw]


