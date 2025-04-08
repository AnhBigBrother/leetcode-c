build: 
	clang -g -Wall -Werror -o ./bin/main main.c ./utils/*.c 

run: 
	clang main.c ./utils/*.c -o ./bin/main && ./bin/main

.PHONY: build run
