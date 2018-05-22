BO = build/interface.o
MO = build/main.o -lncurses
BRO = build/string_funcs.o
CC = gcc -Wall -Werror -o 

all: Hangman

Hangman: build $(BO) $(MO) $(BRO)
	$(CC) Hangman $(MO) $(BO) $(BRO)
ignore: 
	mkdir ignore
build/interface.o: scr/interface.c
	$(CC) $(BO) -c scr/interface.c
build/main.o: scr/main.c 
	$(CC) $(MO) -c scr/main.c -lncurses
build/string_funcs.o: scr/string_funcs.c
	$(CC) $(BRO) -c scr/string_funcs.c
build:
	mkdir build
.PHONY : clean
clean: 
	rm -rf build/*.o
