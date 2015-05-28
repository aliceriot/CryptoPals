CC=gcc
CFLAGS=-I -lm
DEPS = hexConvert.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hexmake: hexToInt.o main.o reverse.o mygetline.o converter.o
	$(CC) -lm -o hexToBase64 hexToInt.o main.o reverse.o mygetline.o converter.o
