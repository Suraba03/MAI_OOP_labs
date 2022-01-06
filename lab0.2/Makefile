CC = g++
CFLAGS = -Wall -g
SOURCES = main.o money.o

all: bin
	./bin

bin: main.o money.o
	g++ main.o money.o -o bin

main.o: money.o
	$(CC) -c main.cpp

money.o: money.cpp
	$(CC) -c money.cpp

clean:
	rm -rf *.o bin