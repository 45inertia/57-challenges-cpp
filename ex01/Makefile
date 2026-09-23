CXXFLAGS := -Wall -Wextra -std=c++20

build/main: build/main.o
	c++ ${CXXFLAGS} build/main.o -o build/main

build/main.o: main.cpp
	mkdir -p build
	c++ ${CXXFLAGS} -c main.cpp -o build/main.o

.PHONY: clean
clean:
	rm -rf build/
