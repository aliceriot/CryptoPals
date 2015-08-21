
def distance(s1, s2):
    return sum(bin(x^y).count('1') for x,y in zip(s1, s2))
