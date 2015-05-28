CC=gcc
CFLAGS=-I -lm
DEPS = hexConvert.h

out/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hexmake: out/hexToInt.o out/main.o out/reverse.o out/mygetline.o out/converter.o
	$(CC) -lm -o hexToBase64.bin out/hexToInt.o out/main.o out/reverse.o out/mygetline.o out/converter.o
