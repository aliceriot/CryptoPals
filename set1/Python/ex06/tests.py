#!/usr/bin/python3

import unittest
from hamming import distance
from blocks import Blocks

class HammingTests(unittest.TestCase):
    def test_example(self):
        self.assertEqual(37, distance(b'this is a test', b'wokka wokka!!!'))

class BlockTests(unittest.TestCase):
    def test_working(self):
        with open("./ex06.txt") as f:
            ctext = ''.join([l.strip() for l in f.readlines()])
        testblocks = Blocks(ctext, [2])
        self.assertNotEqual([], testblocks.blocks[2])


if __name__ == '__main__':
    unittest.main()

