x = 'ciphertext'

def maxxor(s):
    res = []
    for i in range(256):
        chrs = [chr(ord(s) ^ i) for s in x.decode('hex')]
        res.append([score_plaintext(chrs), ''.join(chrs)])
    return max(res, key = lambda x: x[0])


def score_plaintext(s):
    letters = filter(lambda x: 'a'<=z<='z' or 'A'<=x<='Z', s)
    return float(len(letters)) / len(s)

maxxor(x)
