#ifndef SDLGC_H
#define SDLGC_H

#include <SDL2/SDL.h>

#include "gc.h"

class sdlgc: public gc
{
	SDL_Window *win;
	SDL_Surface *srf;

	Uint32 brush_color;

public:
	sdlgc(SDL_Window *new_win);
	virtual ~sdlgc();

	virtual void set_brush_color(unsigned char r, unsigned char g, unsigned char b);
	virtual void box(int x, int y, int w, int h);

	virtual void prepare();
	virtual void commit();

	void resized();
};

#endif
