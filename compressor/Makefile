CC = g++
FLAGS = -Wall -Wextra -std=c++17 -Wshadow -pedantic -I include

all: bin main

test: bin main generator validator checker

main: bin/main.o src/main.cpp
	$(CC) $(FLAGS) bin/main.o -o main

bin/main.o: src/main.cpp
	$(CC) $(FLAGS) -c src/main.cpp -o bin/main.o

check: bin checker

checker: bin/checker.o src/checker.cpp
	$(CC) $(FLAGS) bin/checker.o -o checker

bin/checker.o: src/checker.cpp
	$(CC) $(FLAGS) -c src/checker.cpp -o bin/checker.o

bin:
	mkdir -p bin

valid: bin validator

validator: bin/validator.o src/validator.cpp
	$(CC) $(FLAGS) bin/validator.o -o validator

bin/validator.o: src/validator.cpp
	$(CC) $(FLAGS) -c src/validator.cpp -o bin/validator.o

gen: bin generator

generator: bin/generator.o src/generator.cpp
	$(CC) $(FLAGS) bin/generator.o -o generator

bin/generator.o: src/generator.cpp
	$(CC) $(FLAGS) -c src/generator.cpp -o bin/generator.o

clean:
	rm -rf bin
	rm -f main checker validator generator

.PHONY: all clean
