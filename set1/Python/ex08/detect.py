from ECB import ECBDetector

with open("./ex08.txt") as f:
    hexstrings = [x.strip() for x in f.readlines()]

goodscores = []
for hexstring in hexstrings:
    temp = ECBDetector(hexstring)
    if temp.score > 0:
        goodscores.append((temp.score, hexstring))

score, hexstring = goodscores[0]

print("The best scoring ciphertext:\n{}\nWith {} repeating blocks."\
        .format(hexstring, score))
