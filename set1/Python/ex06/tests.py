#!/usr/bin/python3

import unittest
from hamming import distance

class HammingTests(unittest.TestCase):
    def test_example(self):
        self.assertEqual(37, distance(b'this is a test', b'wokka wokka!!!'))


if __name__ == '__main__':
    unittest.main()

