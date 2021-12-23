ub.exe: main.cpp Makefile
	g++ -o ub.exe -std=c++17 -Og -Wall -pedantic -Wextra main.cpp

tidy: main.cpp
	clang-tidy main.cpp -header-filter=.* -checks=bugprone*,readability*,portability*,misc*

