WARNINGS=-Wall -Wpedantic -Wextra
OPT = -O3
all: main.exe

main.exe: main.cpp Makefile
	g++ -o $@ -std=c++17 $(OPT) $(WARNINGS) main.cpp

clean:
	rm main.exe