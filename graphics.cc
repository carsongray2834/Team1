#include <iostream>
#include "/public/colors.h"
#include "graphics.h"

using namespace std;

void die() {
	std::cout << "BAD INPUT SOMEWHERE!" << std::endl;
	exit(0);
}

void ParticleGraphics::drawPoint(int r, int c) {
	movecursor(r,c);
	setbgcolor(color.r,color.g,color.b);
	cout << " " << flush;
	resetcolor();
}

void ParticleGraphics::drawRect(int r, int c, int w, int h) {
	for (int i = r; i < r + h; i++) {
		for (int j = c; j < c + w; j++) {
	  		drawPoint(i,j);
		}
	}
}

//give the center point row, center point column, total width, then total height
void ParticleGraphics::drawOval(int r, int c, int w, int h) {
	//double cx = c;
	//double cy = r;
	double a = static_cast<double>(w) / 2.0;
	double b = static_cast<double>(h) / 2.0;
	for (int i = r - (h / 2) - 1; i < r + (h / 2) + 1; i++) {
		for (int j = c - (w / 2) - 1; j < c + (w / 2) + 1; j++) {
			double di = i - r;
			double dj = j - c;
			if ((((di*di)/(b*b)) + ((dj*dj)/(a*a))) <= 1.001) {
				setColor(Color{255,0,0});
				drawPoint(i,j);
			}
			else {
				setColor(Color{0,255,0});
				drawPoint(i,j);
			}
		}
	}
}

Color::Color(int new_r, int new_g, int new_b) : r(new_r), g(new_g), b(new_b) {
	if(new_r < 0 || new_g < 0 || new_b < 0) die();
	else if(new_r > 255 || new_b > 255 || new_g > 255) die();
	//r, g, and b must be greater than or equal to 0 and less or equal to  255
}

