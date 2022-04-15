#include "sdlgc.h"

sdlgc::sdlgc(SDL_Window *new_win)
:win(new_win)
{
	srf = SDL_GetWindowSurface(win);
}

sdlgc::~sdlgc()
{
}

void sdlgc::set_color(unsigned char r, unsigned char g, unsigned char b)
{
}

void sdlgc::box(unsigned short x, unsigned short y, unsigned short w, unsigned short h)
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
