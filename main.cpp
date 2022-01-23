#include <iostream>
#include <stdexcept>

#include <SDL2/SDL.h>

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	SDL_Window *win;

	if (SDL_Init(SDL_INIT_VIDEO)) {
		throw runtime_error(SDL_GetError());
	}

	win = SDL_CreateWindow("Tile game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE);

	SDL_Delay(5000);
}
