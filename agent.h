#ifndef AGENT_H
#define AGENT_H

class gc;
class board;

class agent
{
	agent(const agent &);
	agent &operator=(const agent &);

public:
	unsigned short x, y;
	float ox, oy;

	agent()
	{
	}

	void draw(gc *gc, board *b);
	void tick(board *b);
};

#endif
