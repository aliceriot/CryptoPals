CC=gcc
CFLAGS=-I -lm
DEPS = xor.h

out/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hexmake: out/main.o out/charcount.o out/hexfunctions.o out/xorcipher.o
	$(CC) -lm -o xorCipher.bin out/charcount.o out/main.o out/hexfunctions.o out/xorcipher.o
