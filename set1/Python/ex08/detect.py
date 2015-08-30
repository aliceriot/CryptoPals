from ECB import ECBDetector

with open("./ex08.txt") as f:
    hexstrings = [x.strip() for x in f.readlines()]

goodscores = []
for hexstring in hexstrings:
    temp = ECBDetector(hexstring)
    if temp.score > 0:
        goodscores.append((temp.score, hexstring))

print("The best scoring ciphertext:\n{}\nWith {} repeating blocks."\
        .format(goodscores[0][1], goodscores[0][0]))
