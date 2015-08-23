#!/usr/bin/python3

from Keysieve import Keysieve

"""this file actually solves the problem"""

with open("./ex06.txt") as f:
    ciphertext = ''.join([l.strip() for l in f.readlines()])
