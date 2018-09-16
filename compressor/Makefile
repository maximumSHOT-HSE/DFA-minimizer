CC = g++
FLAGS = -Wall -Wextra -std=c++17 -Wshadow -pedantic -Werror

all: bin main

main: bin/main.o src/main.cpp
	$(CC) $(FLAGS) bin/main.o -o main

bin/main.o: src/main.cpp
	$(CC) $(FLAGS) -c src/main.cpp -o bin/main

bin:
	mkdir -p bin

clean:
	rm -rf bin
	rm -f main

.PHONY: all clean
