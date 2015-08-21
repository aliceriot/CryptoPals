

def hamminghelp(numtup):
    numone = bin(numtup[0])[2:]
    numtwo = bin(numtup[1])[2:]
    result = 0
    for pair in zip(numone, numtwo):
        if pair[0] != pair[1]:
            result +=1
    return result

def distance(strone, strtwo):
    sumit = 0
    for pair in zip(map(ord, strone), map(ord, strtwo)):
        print("pair:", pair)
        print("dist:", hamminghelp(pair))
        print("sum:", sumit)
        sumit += hamminghelp(pair)



    return sum(map(hamminghelp, zip(map(ord, strone), map(ord, strtwo))))
    

