#!/bin/bash

make && ciphertext=$(cat 10.txt) key="YELLOW SUBMARINE" iv="0000000000000000" ./matasano
