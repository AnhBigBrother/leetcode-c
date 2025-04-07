build: 
	clang -g -Wall -Werror -o ./bin/main main.c ./libs/*.c 

run: 
	clang main.c ./libs/*.c -o ./bin/main && ./bin/main

.PHONY: build run
