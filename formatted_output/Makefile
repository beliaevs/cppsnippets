WARN=-Wall -Wpedantic -Wextra -Wshadow -Wunused -Wconversion -Wcast-align -Weffc++ 

all: formats.exe


formats.exe: formats.cpp Makefile
	g++ -o formats.exe -std=c++17 $(WARN) formats.cpp

clean:
	rm formats.exe

