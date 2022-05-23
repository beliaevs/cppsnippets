WARNINGS=-Wall -Wpedantic -Wextra
OPT = -O3
all: main.exe benchmark_test.exe

benchmark_test.exe: benchmark_test.cpp Makefile
	g++ -o $@ $(WARNINGS) $(OPT) -I../../3rd_party/benchmark/include -I../../3rd_party/benchmark/build/include -L../../3rd_party/benchmark/build/src -lbenchmark_main -lbenchmark benchmark_test.cpp 

main.exe: main.cpp Makefile
	g++ -o $@ -std=c++17 $(OPT) $(WARNINGS) main.cpp

clean:
	rm main.exe