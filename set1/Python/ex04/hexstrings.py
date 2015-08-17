from XOR import Singlebyte
from textblob import Word

with open('hex.txt') as myfile:
    hexstrings = [x.strip() for x in myfile.readlines()]

goodstrings = []

for hexstring in hexstrings:
    temp = Singlebyte(hexstring)
    for string in temp.strings:
        thing = filter(lambda x: x != [], 
                map(lambda x: Word(x).define(), string.split(' ')))
        if (list(thing)) != []:
            goodstrings.append(string)

for string in goodstrings:
    print(string)
