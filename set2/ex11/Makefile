P=exercise_11
OBJECTS=
CFLAGS=$(shell pkg-config --cflags glib-2.0 openssl) -g -Wall -O3 -std=gnu11
LDFLAGS=
LDLIBS=$(shell pkg-config --libs glib-2.0 openssl) -lm
CC=gcc

$(P): $(OBJECTS)

clean:
	rm exercise_11 *.idx *.log *.scn *.toc *.tex *.pdf

docs:
	cweave exercise_11 && pdftex exercise_11.tex
