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