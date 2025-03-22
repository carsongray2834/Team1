#ifndef PART_H
#define PART_H
#include "graphics.h"

enum Type {STREAMER, BALLISTIC, FIREWORK};

class Particle {
	int x; //columns
	int y; //rows
	double dx; //columns / frame
	double dy; //rows / frame
	double ax = 0; //columns / frame^2
	double ay = 0; // rows / frame^2
	// I left acceleration out of the constructor (since it's optional)
	//so if anyone wants to use it they'll need to use the set_ax/ay functions
	Type type = STREAMER;
	char shape = ' ';
	int life;
	Color c{255,255,255};//feel free to change the default color
public:
	Particle (Color newC = {255, 255, 255}, Type newType = STREAMER, int newX = 0, int newY = 0, double newDx = 0, double newDy = 0, int newLife = 1, char nshape = ' ');
	Color get_color();
	void set_color(Color newC);
	int get_x();
	int get_y();
	void set_x(int nX);
	void set_y(int nY);
	double get_dx();
	double get_dy();
	void set_shape(char ch);
	char get_shape();
	void set_dx(double new_dx);
	void set_dy(double new_dy);
	Type get_type();
	void set_type(Type nType);
	int get_life();
	void set_life(int newLife);
	void set_ax(double n);
	void set_ay(double n);
	double get_ax();
	double get_ay();
	void move();
	ParticleGraphics graphics();
};
#endif
