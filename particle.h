#ifndef PART_H
#define PART_H
#include <iostream>


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
		//r, g, and b must be greater than or equal to 0 and less than 255
	}	
};
class Particle {
	//Data data; holding off on this for now
	int x;
	int y;
	double dx;
	double dy;
	double ax;
	double ay;
	enum Type {STREAMER, BALLISTIC, FIREWORK};
	Type type = STREAMER;
	int lifeFramesLeft;
	Color c{255,255,255};//feel free to change the default color
public:
	int get_x() {};
	int get_y() {};
	void set_x(int nX) {};
	void set_y(int nY) {};
	double get_dx() {};
	double get_dy() {};
	void set_dx(double new_dx) {};
	void set_dy(double new_dy) {};
	Type get_type() {};
	void set_type(Type nType) {};
	int get_life() {};
	void set_life() {};
	void move() {};
};
#endif
