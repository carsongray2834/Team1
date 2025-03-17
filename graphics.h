#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include "particle.h"
#include <vector>

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
	void drawPoint(int x, int y) {}

	//takes upper left point, width, and height
	void drawRect(int x, int y, int w, int h) {}

	//takes center point, width, and height
	void drawOval(int x, int y, int w, int h) {}

	//takes a vector of coords ({x1,y1,x2,y2,x3,y3,...})
	void drawPolygon(vector<int> vertices) {}

	//takes two endpoints
	void drawLine(int x1, int y1, int x2, int y2) {}
};

#endif
