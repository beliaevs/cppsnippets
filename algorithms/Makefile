WARNINGS = -Wall -Wpedantic -Wextra
STANDARD = -std=c++17

all: main.exe

main.exe: main.cpp Makefile
	g++ -o $@ $(WARNINGS) $(STANDARD) $<

clean:
	rm main.exe
	