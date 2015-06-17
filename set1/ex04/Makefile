CC=gcc
CFLAGS=-I -lm
DEPS = src/detection.h

out/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hexmake: out/main.o out/charcount.o out/hexfunctions.o out/xorcipher.o out/detection.o
	$(CC) -lm -o detectXOR.bin out/charcount.o out/main.o out/hexfunctions.o out/xorcipher.o out/detection.o
