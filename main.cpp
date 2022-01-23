#include <iostream>
#include <stdexcept>

#include <SDL2/SDL.h>

#include "framer.h"

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	if (SDL_Init(SDL_INIT_VIDEO)) {
		throw runtime_error(SDL_GetError());
	}

	SDL_Window *win = SDL_CreateWindow("Tile game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE);

	framer fr;

	fr.set_framerate(60);

	SDL_Surface *srf = SDL_GetWindowSurface(win);

	SDL_Event evt;

	for (;;) {
		if (!SDL_WaitEvent(&evt)) {
			throw runtime_error(SDL_GetError());
		}

		switch(evt.type) {
		case SDL_WINDOWEVENT:
			switch (evt.window.event) {
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				srf = SDL_GetWindowSurface(win);
				break;
			}
			break;

		case SDL_QUIT:
			goto out;
		}

		SDL_FillRect(srf, NULL, SDL_MapRGB(srf->format, 0xaa, 0x00, 0x55));
		SDL_UpdateWindowSurface(win);

		fr.next();
	}

out:
	SDL_Quit();
}
