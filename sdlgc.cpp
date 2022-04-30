#include "sdlgc.h"

sdlgc::sdlgc(SDL_Window *new_win)
:win(new_win)
{
	srf = SDL_GetWindowSurface(win);
}

sdlgc::~sdlgc()
{
}

void sdlgc::set_brush_color(unsigned char r, unsigned char g, unsigned char b)
{
	brush_color = SDL_MapRGB(srf->format, r, g, b);
}

void sdlgc::box(int x, int y, int w, int h)
{
	SDL_Rect r;

	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;

	SDL_FillRect(srf, &r, color);
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
