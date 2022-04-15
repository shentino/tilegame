game: board.o framer.o gc.o main.o sdlgc.o
	g++ board.o framer.o gc.o main.o sdlgc.o -o game `sdl2-config --libs`
board.o: board.cpp board.h gc.h sdlgc.h tile.h
	g++ -ggdb3 -c board.cpp -o board.o `sdl2-config --cflags`
main.o: main.cpp board.h framer.h sdlgc.h tile.h
	g++ -ggdb3 -c main.cpp -o main.o `sdl2-config --cflags`
framer.o: framer.cpp framer.h
	g++ -ggdb3 -c framer.cpp -o framer.o
gc.o: gc.cpp gc.h
	g++ -ggdb3 -c gc.cpp -o gc.o
sdlgc.o: sdlgc.cpp gc.h sdlgc.h
	g++ -ggdb3 -c sdlgc.cpp -o sdlgc.o `sdl2-config --cflags`
