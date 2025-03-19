#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

struct Color {
	int r = 0;
	int g = 0;
	int b = 0;
	Color(int new_r, int new_g, int new_b);
};

class ParticleGraphics {
	Color color{100,10,150};
	public:
	ParticleGraphics(Color c) {
		color = c;
	}
	void setColor(Color c) {
		color = c;
	}
	Color getColor() {
		return color;
	}
	//takes point coords
	void drawPoint(int r, int c);

	//takes upper left point, width, and height
	void drawRect(int x, int y, int w, int h);

	//takes center point, width, and height
	void drawOval(int x, int y, int w, int h);

	//takes a vector of coords ({x1,y1,x2,y2,x3,y3,...})
	void drawPolygon(std::vector<int> vertices);

	//takes two endpoints
	void drawLine(int x1, int y1, int x2, int y2);
};

#endif
