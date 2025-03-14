#ifndef PART_H
#define PART_H
#include <iostream>

const double g = 9.80;
//GRAVITY DONT CHANGE



//we can probably move the Data struct into this file, since this class will probably take it instead of Node. 
void die() {
	std::cout << "BAD INPUT SOMEWHERE!" << std::endl;
	exit(1);
}

struct Color {
	int r = 0;
	int g = 0;
	int b = 0;

	Color(int new_r, int new_g, int new_b) : r(new_r), g(new_g), b(new_b) {
		if(new_r < 0 || new_g < 0 || new_b < 0) die();
		else if(new_r > 255 || new_b > 255 || new_g > 255) die();
		//r, g, and b must be greater than or equal to 0 and less than 255
	}	
};
class Particle {
	//TODO particle needs constructor
	int x;
	int y;
	double dx;
	double dy;
	//acceleration not needed
	enum Type {STREAMER, BALLISTIC, FIREWORK};
	Type type = STREAMER;
	int lifeFramesLeft;
	Color c{255,255,255};//feel free to change the default color
public:
	int get_x() {return 1;}
	int get_y() {return 1;}
	void set_x(int nX) {}
	void set_y(int nY) {}
	double get_dx() {return 3.14;}
	double get_dy() {return 3.14;}
	void set_dx(double new_dx) {}
	void set_dy(double new_dy) {}
	Type get_type() {return STREAMER;}
	void set_type(Type nType) {}
	int get_life() {return 100;}
	void set_life() {}
	void move() {}
};
#endif
