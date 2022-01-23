game: framer.o gc.o main.o sdlgc.o
	g++ framer.o gc.o main.o sdlgc.o -o game `sdl2-config --libs`
main.o: main.cpp framer.h sdlgc.h
	g++ -c main.cpp -o main.o `sdl2-config --cflags`
framer.o: framer.cpp framer.h
	g++ -c framer.cpp -o framer.o
gc.o: gc.cpp gc.h
	g++ -c gc.cpp -o gc.o
sdlgc.o: sdlgc.cpp gc.h sdlgc.h
	g++ -c sdlgc.cpp -o sdlgc.o `sdl2-config --cflags`
