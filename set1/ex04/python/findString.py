import sys

filename = sys.argv[1]

with open(filename, 'r') as myfile:
    raw = myfile.readlines()


hexArray = [hexString(i) for i in raw]


