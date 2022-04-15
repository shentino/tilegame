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

	void tick();
	void draw(gc *gc);
};

#endif
