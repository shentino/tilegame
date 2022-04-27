# phony targets
all: game
clean:
	rm -f game *.o

.PHONY: all cean

# main output
game: agent.o board.o framer.o gc.o main.o sdlgc.o
	g++ agent.o board.o framer.o gc.o main.o sdlgc.o -o game `sdl2-config --libs`

# object files
agent.o: agent.cpp agent.h board.h gc.h
	g++ -ggdb3 -c agent.cpp -o agent.o
board.o: board.cpp board.h gc.h sdlgc.h
	g++ -ggdb3 -c board.cpp -o board.o
main.o: main.cpp board.h framer.h sdlgc.h
	g++ -ggdb3 -c main.cpp -o main.o `sdl2-config --cflags`
framer.o: framer.cpp framer.h
	g++ -ggdb3 -c framer.cpp -o framer.o
gc.o: gc.cpp gc.h
	g++ -ggdb3 -c gc.cpp -o gc.o
sdlgc.o: sdlgc.cpp gc.h sdlgc.h
	g++ -ggdb3 -c sdlgc.cpp -o sdlgc.o `sdl2-config --cflags`
