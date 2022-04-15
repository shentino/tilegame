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
	/* for now just assume each tile needs to be 32 pixels wide */

	/* eventually we'll need to consult the ui for zoom and scroll information */

	unsigned short centerx, centery;

	centerx = gc->get_width() / 2;
	centery = gc->get_height() / 2;

	unsigned short offsetx, offsety;

	offsetx = centerx - (width * 16) / 2;
	offsety = centery - (height * 16) / 2;

	for (unsigned short y = 0; y < height; y++) {
		for (unsigned short x = 0; x < width; x++) {
			unsigned char terrain = tiles[y * height + x].terrain;

			gc->set_color(0, terrain, 0);
			gc->box(offsetx + x * 16, offsety + y * 16, 16, 16);
		}
	}
}

void board::tick()
{
	size_t sz;

	sz = width * height;

	for (size_t i = 0; i < sz; i++) {
		tiles[i].terrain = lrand48() & 0xff;
	}
}
