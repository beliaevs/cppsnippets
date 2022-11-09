all: casts.exe casts_clang.exe

casts.exe: casts.cpp Makefile
	g++ -std=c++17 -Wall -Wpedantic -Wextra -o casts.exe casts.cpp

clang: casts_clang.exe

casts_clang.exe: casts.cpp Makefile
	clang++ -std=c++17 -o casts_clang.exe casts.cpp -Wall -Wpedantic -Wextra -fsanitize=undefined

clean:
	rm casts.exe casts_clang.exe
