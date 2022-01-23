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

	virtual void prepare();
	virtual void commit();
};

#endif
