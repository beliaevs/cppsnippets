WARNINGS = -Wall -Wpedantic -Wextra
STANDARD = -std=c++17

CPPFILES = main.cpp copy.cpp sort.cpp utility.cpp
HFILES = registry.h utility.h

all: main.exe

main.exe:  $(CPPFILES) $(HFILES) Makefile
	g++ -o $@ $(WARNINGS) $(STANDARD) $(CPPFILES)

clean:
	rm main.exe
	