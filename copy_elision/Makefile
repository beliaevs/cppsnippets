all: copy_elision.exe no_copy_elision.exe

copy_elision.exe: copy_elision.cpp spy.h Makefile
	g++ -o copy_elision.exe -Wall -pedantic -Wextra -std=c++17 copy_elision.cpp

no_copy_elision.exe: copy_elision.cpp spy.h Makefile
	g++ -o no_copy_elision.exe -Wall -pedantic -Wextra -std=c++11 -fno-elide-constructors copy_elision.cpp
	
clean:
	rm copy_elision.exe
	rm no_copy_elision.exe
