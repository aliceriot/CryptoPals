CC=gcc
CFLAGS=-I -lm
DEPS = hextobase64.h

out/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hexmake: out/functions.o out/main.o
	$(CC) -lm -o hexToBase64.bin out/functions.o out/main.o
