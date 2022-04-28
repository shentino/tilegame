#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "gc.h"

#define TILESIZE 32

using namespace std;

struct tile
{
	unsigned char terrain;
};

class board
{
	vector<tile> tiles;
	unsigned short width, height;

	board();
	board(const board &);
	board &operator=(const board &);

public:
	board(unsigned short new_width, unsigned short new_height);
	~board();

	unsigned short get_width()
	{
		return width;
	}

	unsigned short get_height()
	{
		return height;
	}

	void tick();

	void draw(gc *gc);
};

#endif
