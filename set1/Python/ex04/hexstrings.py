from XOR import Singlebyte

with open('hex.txt') as myfile:
    hexstrings = [x.strip() for x in myfile.readlines()]

possible = []
poskeys = []

for hexstring in hexstrings:
    temp = Singlebyte(hexstring)
    strings = temp.strings
    keys = temp.potk
    if strings != []:
        possible.append(strings[:])
        poskeys.append(keys[:])


for enum in enumerate(possible):
    print("\n {} \n {} \n\n".format(possible[enum[0]], poskeys[enum[0]]))
