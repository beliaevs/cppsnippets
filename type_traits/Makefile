WARN_OPTS=-Wall -Wpedantic -Wextra #-Weffc++

all: main.exe

main.exe: main.cpp table.h Makefile
	g++ -o $@ -std=c++17 $(WARN_OPTS) $<

clean:
	rm main.exe
	