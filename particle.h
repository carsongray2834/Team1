#ifndef PART_H
#define PART_H
#include <iostream>

const double g = 9.80;
//GRAVITY DONT CHANGE



//we can probably move the Data struct into this file, since this class will probably take it instead of Node. 
void die() {
	std::cout << "BAD INPUT SOMEWHERE!" << std::endl;
	exit(0);
}


enum Type {STREAMER, BALLISTIC, FIREWRK};

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
	int x;
	int y;
	double dx;
	double dy;
	//acceleration not needed
	Type type = STREAMER;
	int life;
	Color c{255,255,255};//feel free to change the default color
public:
	Particle (Color newC = {255, 255, 255}, Type newType = STREAMER, int newX = 0, int newY = 0, double newDx = 0, double newDy = 0, int newLife = 1){
		c = newC;
		type = newType;
		if (newX < 0) newX = 0;
		x = newX;
		if (newY < 0) newY = 0;
		y = newY;
		dx = newDx;
		dy = newDy;
		if (newLife < 0) newLife = 0;
		life = newLife;
	}
	Color get_color() {return c;}
	void set_color(Color newC) {c = newC;}
	int get_x(){return x;}
	int get_y(){return y;}
	void set_x(int nX) {
		if (nX < 0) nX = 0;
		x = nX;
	}
	void set_y(int nY) {
		if (nY < 0) nY = 0;
		y = nY;
	}
	double get_dx() {return dx;}
	double get_dy() {return dy;}
	void set_dx(double new_dx) {dx = new_dx;}
	void set_dy(double new_dy) {dy = new_dy;}
	Type get_type() {return type;}
	void set_type(Type nType) {type = nType;}
	int get_life() {return life;}
	void set_life(int newLife) {
		if (newLife < 0) newLife = 0;
		life = newLife;
	}
	void move() {}
	void draw() {}
};
#endif
