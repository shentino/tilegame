#ifndef SDLGC_H
#define SDLGC_H

#include <SDL2/SDL.h>

#include "gc.h"

class sdlgc: public gc
{
	SDL_Window *win;
	SDL_Surface *srf;

public:
	sdlgc(SDL_Window *new_win);
	virtual ~sdlgc();

	virtual void prepare();
	virtual void commit();

	void resized();
};

#endif