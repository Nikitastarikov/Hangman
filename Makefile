BO = build/interface.o -lncurses
MO = build/main.o -lncurses
BRO = build/string_funcs.o 
CC = gcc -Wall -Werror -o 

all: Hangman test

Hangman: build $(BO) $(MO) $(BRO)
	$(CC) Hangman $(MO) $(BO) $(BRO)
ignore: 
	mkdir ignore
build/interface.o: scr/interface.c
	$(CC) $(BO) -c scr/interface.c -lncurses
build/main.o: scr/main.c 
	$(CC) $(MO) -c scr/main.c -lncurses
build/string_funcs.o: scr/string_funcs.c 
	$(CC) $(BRO) -c scr/string_funcs.c 
test: build/test.o build/ctest.o build/string_funcs.o
	gcc -Wall build/test.o build/ctest.o build/string_funcs.o -o test -lncurses	
build/test.o: scr/test.c 
	gcc -I thirdparty -I scr/headers -c scr/test.c -o build/test.o
build/ctest.o: scr/ctest.c
	gcc -I thirdparty -c scr/ctest.c -o build/ctest.o
build:
	mkdir build
.PHONY : clean
clean: 
	rm -rf build/*.o
