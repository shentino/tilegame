#include <cstddef>
#include <cstdlib>

#include "board.h"

board::board(unsigned short new_width, unsigned short new_height)
:width(new_width), height(new_height)
{
	size_t sz;

	sz = width * height;

	tiles.resize(sz);

	for (size_t i = 0; i < sz; i++) {
		tiles[i].terrain = 0;
	}
}

void board::draw(gc *gc)
{
	/* eventually we'll need to consult the ui for zoom and scroll information */

	int centerx, centery;

	centerx = gc->get_width() / 2;
	centery = gc->get_height() / 2;

	int offsetx, offsety;

	offsetx = centerx - (width * TILESIZE) / 2;
	offsety = centery - (height * TILESIZE) / 2;

	for (unsigned short y = 0; y < height; y++) {
		for (unsigned short x = 0; x < width; x++) {
			unsigned char terrain = tiles[y * height + x].terrain;

			gc->set_brush_color(0, terrain, 0);
			gc->box(offsetx + x * TILESIZE, offsety + y * TILESIZE, TILESIZE, TILESIZE);
		}
	}
}

void board::tick()
{
}
