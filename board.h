#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "tile.h"
#include "gc.h"

using namespace std;

class board
{
	vector<tile> tiles;
	int width, height;

	board();
	board(const board &);
	board &operator=(const board &);

public:
	board(int new_width, int new_height);
	~board();

	int get_width()
	{
		return width;
	}

	int get_height()
	{
		return height;
	}

	void tick();
	void draw(gc *gc);
};

#endif
