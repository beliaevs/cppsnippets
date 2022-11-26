CC=g++
CCFLAGS=-std=c++20 -Wall -pedantic -Wextra
TARGETS=main.exe lambda.exe

all: $(TARGETS)

main.exe: main.cpp Makefile
	$(CC) -o main.exe $(CCFLAGS) main.cpp

lambda.exe: lambda.cpp Makefile
	$(CC) -o lambda.exe $(CCFLAGS) lambda.cpp

clean:
	rm $(TARGETS)

