#include <iostream>
#include "/public/colors.h"
#include "graphics.h"

using namespace std;

void die() {
	std::cout << "BAD INPUT SOMEWHERE!" << std::endl;
	exit(0);
}

void ParticleGraphics::drawPoint(int r, int c, Color color) {
	movecursor(r,c);
	setbgcolor(color.r,color.g,color.b);
	cout << " " << flush;
}

Color::Color(int new_r, int new_g, int new_b) : r(new_r), g(new_g), b(new_b) {
	if(new_r < 0 || new_g < 0 || new_b < 0) die();
	else if(new_r > 255 || new_b > 255 || new_g > 255) die();
	//r, g, and b must be greater than or equal to 0 and less or equal to  255
}

