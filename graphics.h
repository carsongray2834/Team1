#ifndef GRAPH_H
#define GRAPH_H

#include "/public/colors.h"
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
	ParticleGraphics(Color c = Color {255,0,0}) {
		color = c;
	}
	void setColor(Color c) {
		color = c;
	}
	void setColor(int r, int g, int b) {
		color = {r, g, b};
	}
	Color getColor() {
		return color;
	}
	//takes point coords
	void drawPoint(int r, int c);
	//draw point with char
	void drawPoint(int r, int c, char ch);
	//draw point with color
	void drawPoint(int r, int c, Color co);

	//takes upper left point, width, and height
	void drawRect(int r, int c, int w, int h);

	//takes center point, width, and height
	void drawOval(int x, int y, int w, int h);

	//takes a vector of coords ({x1,y1,x2,y2,x3,y3,...})
	//only convex polygons
	//list points counterclockwise and in order, do not repeat first point
	void drawPolygon(std::vector<int> vertices);
	//const by reference ^

	//takes two endpoints
	//works better for lines closer to 45deg or flat, might not work for vertical lines
	void drawLine(int x1, int y1, int x2, int y2);
};

#endif
