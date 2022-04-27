GCCFLAGS=-std=c++17 -Wall -pedantic -Wextra
CLANGFLAGS=-std=c++17 -Wall -pedantic -Wextra -Wc++17-compat-pedantic
CPPFILES=main.cpp
HFILES=cont.h util.h

all: move.exe cmove.exe

move.exe: $(CPPFILES) $(HFILES) Makefile
	g++ -o move.exe $(GCCFLAGS) $(CPPFILES)

cmove.exe: $(CPPFILES) $(HFILES) Makefile
	clang++ -o cmove.exe $(CLANGFLAGS) $(CPPFILES)

clean:
	rm move.exe
	rm cmove.exe

