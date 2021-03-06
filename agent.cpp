#include "agent.h"
#include "board.h"

agent::agent(board *b)
{
	x = b->get_width() / 2;
	y = b->get_height() / 2;
}

void agent::draw(gc *gc, board *b)
{
	int offsetx, offsety;

	offsetx = gc->get_width() / 2;
	offsety = gc->get_height() / 2;

	offsetx -= (b->get_width() * TILESIZE) / 2;
	offsety -= (b->get_height() * TILESIZE) / 2;

	gc->set_brush_color(0xff, 0xff, 0xff);
	gc->box(offsetx + x * TILESIZE + TILESIZE / 4, offsety + y * TILESIZE + TILESIZE / 4, TILESIZE / 2, TILESIZE / 2);
}

void agent::tick(board *b)
{
}
