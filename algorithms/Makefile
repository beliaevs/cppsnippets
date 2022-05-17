WARNINGS = -Wall -Wpedantic -Wextra
STANDARD = -std=c++17

all: main.exe

main.exe: main.cpp copy.cpp registry.h utility.h Makefile
	g++ -o $@ $(WARNINGS) $(STANDARD) main.cpp copy.cpp

clean:
	rm main.exe
	