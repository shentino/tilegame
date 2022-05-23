#include <iostream>
#include <stdexcept>
#include <list>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
		(*ab++)->tick(b);
	}

	b->tick();
}

static void spawn_agent()
{
	agent *a = new agent(b);

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

static void load_art()
{
	SDL_Surface *rocksrf = IMG_Load("art/rock.png");

	if (!rocksrf) {
		throw runtime_error(IMG_GetError());
	}

	SDL_Surface *soilsrf = IMG_Load("art/soil.png");

	if (!soilsrf) {
		throw runtime_error(IMG_GetError());
	}
}

int main(int argc, char *argv[], char *envp[])
{
	if (SDL_Init(SDL_INIT_VIDEO)) {
		throw runtime_error(SDL_GetError());
	}

	int flags = IMG_INIT_PNG;
	int aflags = IMG_Init(flags);

	if (flags != aflags) {
		throw runtime_error(IMG_GetError());
	}

	load_art();

	SDL_Window *win = SDL_CreateWindow("Tile game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE);

	framer fr;
	fr.set_framerate(60);

	SDL_Surface *srf = SDL_GetWindowSurface(win);

	gc = new sdlgc(win);
	b = new board(BOARDSIZE, BOARDSIZE);

	for (int i = 0; i < 16; i++) {
		spawn_agent();
	}

	/* catch preemptive events */

	if (poll()) {
		goto out;
	}

	if (resized) {
		gc->resized();
	}

	/* initial display */
	render();

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
