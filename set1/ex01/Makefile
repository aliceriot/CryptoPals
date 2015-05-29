CC=gcc
CFLAGS=-I -lm
DEPS = hexConvert.h

out/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hexmake: out/hexToInt.o out/main.o out/reverse.o out/mygetline.o out/converter.o out/intToBase64.o out/returnVal.o out/returnNum.o out/base64String.o
	$(CC) -lm -o hexToBase64.bin out/hexToInt.o out/main.o out/reverse.o out/mygetline.o out/converter.o out/intToBase64.o out/returnVal.o out/returnNum.o out/base64String.o
