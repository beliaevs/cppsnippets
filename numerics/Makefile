CPP = g++
WARN = -Wall -Wextra -Wpedantic

all: inttest.exe main.exe


inttest.exe: inttest.cpp Makefile
	$(CPP) -o inttest.exe $(WARN) inttest.cpp

main.exe: main.cpp valarray_test.cpp all_tests.h Makefile 
	$(CPP) -o main.exe $(WARN) main.cpp valarray_test.cpp

clean:
	rm main.exe
	rm inttest.exe