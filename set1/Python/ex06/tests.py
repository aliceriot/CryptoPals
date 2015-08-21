import unittest
from hamming import distance

class HammingTests(unittest.TestCase):
    def test_example(self):
        self.assertEqual(37, distance('this is a test', 'wokka wokka!!!'))


if __name__ == '__main__':
    unittest.main()

