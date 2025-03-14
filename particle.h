#ifndef PART_H
#define PART_H


//we can probably move the Data struct into this file, since this class will probably take it instead of Node. 

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
	Color c(255,255,255);//feel free to change the default color
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
}
#endif
