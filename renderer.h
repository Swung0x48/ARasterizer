#ifndef ARASTERIZER_RENDERER
#define ARASTERIZER_RENDERER

#include "tgaimage.h"

class context {
public:
	context(int w, int h);

	void line(float x0, float y0, float x1, float y1, TGAColor color);

	TGAImage image;
	int width;
	int height;
private:
};


#endif