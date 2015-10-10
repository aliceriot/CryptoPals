P=matasano
OBJECTS=
CFLAGS=$(shell pkg-config --cflags gsl glib-2.0) -g -Wall -O3 -std=gnu11
LDFLAGS=
LDLIBS=$(shell pkg-config --libs gsl glib-2.0) -lm
CC=gcc

$(P): $(OBJECTS)
