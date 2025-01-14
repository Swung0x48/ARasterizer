#include "renderer.h"

context::context(int w, int h): 
	width(w), height(h), 
	image(w, h, TGAImage::RGB)
{
	
}

void context::line(float x0, float y0, float x1, float y1, TGAColor color)
{
	float k = (y0 - y1) / (x0 - x1);
	float delta_x = 1. / width / 2.;
	float delta_y = 1. / height / 2.;

	if (abs(k) < 1) {
		for (float x = x0; x <= x1; x += delta_x) {
			float t = (x - x0) / (x1 - x0);
			float y = y0 + (y1 - y0) * t;

			int nx = x * width;
			int ny = y * height;
			image.set(nx, ny, color);
		}
	}
	else {
		for (float y = y0; y <= y1; y += delta_y) {
			float t = (y - y0) / (y1 - y0);
			float x = x0 + (x1 - x0) * t;

			int nx = x * width;
			int ny = y * height;
			image.set(nx, ny, color);
		}
	}
}
