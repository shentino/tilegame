#include <iostream>
#include <stdexcept>
#include <list>

#include <SDL2/SDL.h>

#include "agent.h"
#include "board.h"
#include "framer.h"
#include "sdlgc.h"

using namespace std;

static board *b;
static sdlgc *gc;
static bool resized;
static list<agent *> agents;

static void render()
{
	gc->prepare();

	b->draw(gc);

	list<agent *>::iterator ab, ae;

	ab = agents.begin();
	ae = agents.end();

	while (ab != ae) {
		(*ab)->draw(gc, b);
		ab++;
	}

	gc->commit();
}

static void process()
{
	list<agent *>::iterator ab, ae;

	ab = agents.begin();
	ae = agents.end();

	while (ab != ae) {
		(*ab++)->tick();
	}

	b->tick();
}

static void spawn_agent()
{
	agent *a = new agent;

	a->x = lrand48() % b->get_width();
	a->y = lrand48() % b->get_height();
	a->ox = 0.0;
	a->oy = 0.0;

	agents.push_back(a);
}

static bool poll()
{
	SDL_Event evt;

	while (SDL_PollEvent(&evt)) {
		switch(evt.type) {
		case SDL_WINDOWEVENT:
			switch (evt.window.event) {
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				resized = true;
				break;
			}
			break;

		case SDL_QUIT:
			return true;
		}
	}

	return false;
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

	gc = new sdlgc(win);
	b = new board(16, 16);

	for (int i = 0; i < 16; i++) {
		spawn_agent();
	}

	/* initial display */
	render();

	/* catch any preemptive events */
	resized = false;

	if (poll()) {
		goto out;
	}

	for (;;) {
		resized = false;

		if (poll()) {
			goto out;
		}

		if (resized) {
			resized = false;
			gc->resized();
		}

		process();
		render();

		fr.next();
	}

out:
	SDL_Quit();
}
