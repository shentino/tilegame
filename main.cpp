#include <iostream>
#include <stdexcept>

#include <SDL2/SDL.h>

#include "framer.h"
#include "sdlgc.h"
#include "board.h"

using namespace std;

static board *b;
static sdlgc *gc;
static time_t last;

static void render()
{
	gc->prepare();
	gc->commit();
}

static void process()
{
	time_t now;

	time(&now);

	if (now != last) {
		last = now;
	}
}

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

	gc = new sdlgc(win);
	b = new board(16, 16);

	/* initial display */
	render();

	for (;;) {
		fr.next();

		if (!SDL_WaitEvent(&evt)) {
			throw runtime_error(SDL_GetError());
		}

		switch(evt.type) {
		case SDL_WINDOWEVENT:
			switch (evt.window.event) {
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				gc->resized();
				break;
			}
			break;

		case SDL_QUIT:
			goto out;
		}

		process();
		render();
	}

out:
	SDL_Quit();
}
