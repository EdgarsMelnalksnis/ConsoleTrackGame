all: main

main: main.cpp
	g++ -o txt_game main.cpp -lncurses

.PHONY: all clean

clean: 
	rm -rf txt_game 
