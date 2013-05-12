XFLAGS= -std=c++11 -pedantic -Wall -Wextra -O -Wctor-dtor-privacy -Wnon-virtual-dtor -Woverloaded-virtual -Wsign-promo

CXXFLAGS+= $(shell pkg-config --cflags gtkmm-3.0)
LDFLAGS+= $(shell pkg-config --libs gtkmm-3.0)

all: main

main: main.o checkers.o cwin.o piece.o
	g++ $^ $(LDFLAGS) -o $@

checkers.o: checkers.h checkers.cc

cwin.o: cwin.h cwin.cc

piece.o: piece.h piece.cc

main.o: main.cc checkers.o piece.o

clean:
	rm -rf *.o main	
