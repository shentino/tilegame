#include "sdlgc.h"

sdlgc::sdlgc(SDL_Window *new_win)
:win(new_win)
{
	srf = SDL_GetWindowSurface(win);
}

sdlgc::~sdlgc()
{
}

void sdlgc::prepare()
{
	width = srf->w;
	height = srf->h;

	SDL_FillRect(srf, NULL, SDL_MapRGB(srf->format, 0x55, 0x55, 0x55));
}

void sdlgc::commit()
{
	SDL_UpdateWindowSurface(win);
}

void sdlgc::resized()
{
	srf = SDL_GetWindowSurface(win);
}
