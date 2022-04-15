#include "board.h"

board::board(int new_width, int new_height)
:width(new_width), height(new_height)
{
	int sz;

	sz = width * height;

	tiles.resize(sz);

	for (int i = 0; i < sz; i++) {
		tiles[i].terrain = 0;
	}
}

void board::draw(gc *gc)
{
	/* for now just assume each tile needs to be 32 pixels wide */

	/* eventually we'll need to consult the ui for zoom and scroll information */

	int centerx, centery;

	centerx = gc->get_width() / 2;
	centery = gc->get_height() / 2;
}