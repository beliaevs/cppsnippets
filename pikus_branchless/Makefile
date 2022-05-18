WARNINGS = -Wall -Wextra -Wpedantic

all: main.exe

main.exe: main.cpp Makefile
	g++ -o $@ -std=c++17 $(WARNINGS) -O3 main.cpp

clean:
	rm main.exe