CC=gcc
CFLAGS=-I -lm
DEPS = fixedXOR.h

out/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hexmake: out/functions.o out/main.o
	$(CC) -lm -o fixedXOR.bin out/functions.o out/main.o
