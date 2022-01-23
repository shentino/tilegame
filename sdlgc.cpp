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

	SDL_Rect r;

	r.w = width / 2;
	r.h = height / 2;
	r.x = r.w / 2;
	r.y = r.h / 2;

	SDL_FillRect(srf, &r, SDL_MapRGB(srf->format, 0x55, 0x55, 0x55));
}

void sdlgc::commit()
{
	SDL_UpdateWindowSurface(win);
}

void sdlgc::resized()
{
	srf = SDL_GetWindowSurface(win);
}
