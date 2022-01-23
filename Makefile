game: framer.o main.o
	g++ framer.o main.o -o game `sdl2-config --libs`
main.o: main.cpp framer.h
	g++ -c main.cpp -o main.o `sdl2-config --cflags`
framer.o: framer.cpp framer.h
	g++ -c framer.cpp -o framer.o
