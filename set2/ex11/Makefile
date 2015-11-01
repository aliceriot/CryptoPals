P=exercise_11
OBJECTS=
CFLAGS=$(shell pkg-config --cflags gsl glib-2.0 openssl) -g -Wall -O3 -std=gnu11
LDFLAGS=
LDLIBS=$(shell pkg-config --libs gsl glib-2.0 openssl) -lm
CC=gcc

$(P): $(OBJECTS)
