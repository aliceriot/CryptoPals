
def distance(strone, strtwo):
    s1 = bytearray(strone)
    s2 = bytearray(strtwo)

    return sum(bin(x^y).count('1') for x,y in zip(s1, s2))
