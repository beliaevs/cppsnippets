GCCFLAGS=-std=c++20 -Wall -pedantic -Wextra
CLANGFLAGS=-std=c++17 -Wall -pedantic -Wextra -Wc++17-compat-pedantic
CPPFILES=main.cpp
HFILES=cont.h util.h

all: move.exe cmove.exe rvalue_refs.exe forward.exe default_members.exe expression_category.exe

move.exe: $(CPPFILES) $(HFILES) Makefile
	g++ -o move.exe $(GCCFLAGS) $(CPPFILES)

cmove.exe: $(CPPFILES) $(HFILES) Makefile
	clang++ -o cmove.exe $(CLANGFLAGS) $(CPPFILES)

clean:
	rm move.exe
	rm cmove.exe
	rm rvalue_refs.exe
	rm forward.exe
	rm default_members.exe

rvalue_refs.exe: rvalue_refs.cpp Makefile
	g++ -o rvalue_refs.exe $(GCCFLAGS) rvalue_refs.cpp

forward.exe: forward.cpp Makefile
	g++ -o forward.exe $(GCCFLAGS) forward.cpp

default_members.exe: default_members.cpp spy.h Makefile
	g++ -o default_members.exe $(GCCFLAGS) default_members.cpp

expression_category.exe: expression_category.cpp Makefile
	g++ -o expression_category.exe $(GCCFLAGS) expression_category.cpp
