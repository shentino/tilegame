#ifndef GC_H
#define GC_H

class gc
{
protected:
	// these must be set before drawing begins, cannot change during frame
	unsigned short width, height;

public:
	gc();
	virtual ~gc();

	unsigned short get_width()
	{
		return width;
	}

	unsigned short get_height()
	{
		return height;
	}

	virtual void set_color(unsigned char r, unsigned char g, unsigned char b) = 0;
	virtual void box(unsigned short x, unsigned short y, unsigned short w, unsigned short h) = 0;

	virtual void prepare() = 0;
	virtual void commit() = 0;
};

#endif
