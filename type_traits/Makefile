WARN_OPTS=-Wall -Wpedantic -Wextra #-Weffc++

all: main.exe type_sizes.exe

main.exe: main.cpp table.h Makefile
	g++ -o $@ -std=c++17 $(WARN_OPTS) $<

type_sizes.exe: type_sizes.cpp Makefile
	g++ -o $@ -std=c++17 $(WARN_OPTS) $<

clean:
	rm main.exe type_size.exe

	