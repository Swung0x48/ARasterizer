#include <iostream>
#include <algorithm>

#include "tgaimage.h"
#include "renderer.h"
#include "model.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255,   0,   0,   255);
const TGAColor green = TGAColor(  0, 255,   0,   255);
const TGAColor blue  = TGAColor(  0,   0, 255,   255);



int test_drawline(context* ctx) {
	ctx->line(0.1, 0.1, 0.7, 0.3, white);
	ctx->line(0.1, 0.1, 0.3, 0.7, red);
	ctx->line(0.1, 0.1, 0.7, 0.7, green);

	ctx->image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	ctx->image.write_tga_file("output.tga");
	return 0;
}

int test_wireframe(context* ctx) {
	Model m("./african_head.obj");
	Model* model = &m;

	float minx = 1e9, maxx = -1e9, miny = 1e9, maxy = -1e9;

	for (int i = 0; i < model->nverts(); ++i) {
		Vec3f v0 = model->vert(i);
		minx = std::min(v0.x, minx);
		maxx = std::max(v0.x, maxx);
		miny = std::min(v0.y, miny);
		maxy = std::max(v0.y, maxy);
	}

	for (int i = 0; i < model->nfaces(); ++i) {
		std::vector<int> face = model->face(i);
		for (int j = 0; j < 3; j++) {
			Vec3f v0 = model->vert(face[j]);
			Vec3f v1 = model->vert(face[(j + 1) % 3]);
			float x0 = (v0.x - minx) / (maxx - minx);
			float y0 = (v0.y - miny) / (maxy - miny);
			float x1 = (v1.x - minx) / (maxx - minx);
			float y1 = (v1.y - miny) / (maxy - miny);
			ctx->line(x0, y0, x1, y1, white);
		}
	}

	ctx->image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	ctx->image.write_tga_file("output.tga");
	return 0;
}

int main(int argc, char** argv) {
	context ctx(500, 500);
	//return test_drawline(&ctx);
	return test_wireframe(&ctx);
}
