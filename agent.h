#ifndef AGENT_H
#define AGENT_H

class gc;
class board;

class agent
{
public:
	unsigned short x, y;
	float ox, oy;

	void draw(gc *gc, board *b);
};

#endif
