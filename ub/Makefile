ASAN_OPTS=-fsanitize=address

all: ub.exe constref.exe nullptr.exe

ub.exe: main.cpp Makefile
	g++ -o ub.exe -std=c++17 -Og -Wall -pedantic -Wextra main.cpp

constref.exe: constref.cpp Makefile
	g++ -o constref.exe -std=c++20 -Og $(ASAN_OPTS) -fno-omit-frame-pointer -Wall -pedantic -Wextra constref.cpp

nullptr.exe: nullptr.cpp Makefile # -O2 gives "valid", no optimization gives "nullptr dereferencing"
	g++ -o nullptr.exe -std=c++17 -Wall -pedantic -Wextra nullptr.cpp

tidy: main.cpp
	clang-tidy main.cpp -header-filter=.* -checks=bugprone*,readability*,portability*,misc*

clean:
	rm ub.exe
	rm constref.exe

