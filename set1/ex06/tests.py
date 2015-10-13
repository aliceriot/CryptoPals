#!/usr/bin/python3

import unittest
from hamming import distance
from blocks import Blocks
from base64 import b64decode

class HammingTests(unittest.TestCase):
    def test_example(self):
        self.assertEqual(37, distance(b'this is a test', b'wokka wokka!!!'))

class BlockTests(unittest.TestCase):
    def test_working(self):
        with open("./ex06.txt") as f:
            ctext = b64decode(''.join([l.strip() for l in f.readlines()]))
        testblocks = Blocks(ctext, [2])
        self.assertNotEqual([], testblocks.blocks[2])
    def test_small_input(self):
        b = Blocks(bytearray([1,2,3,4]),[2])
        self.assertEqual(b.blocks[2], [bytearray([1,3]), bytearray([2,4])])
    def test_slightly_bigger(self):
        b = Blocks(bytearray([1,2,3,4,5,6]),[2])
        self.assertEqual(b.blocks[2], [bytearray([1,3,5]), bytearray([2,4,6])])


if __name__ == '__main__':
    unittest.main()

