#ifndef CARSON_H
#define CARSON_H
#include <map>

class static_mass {
	int x;
	int y;
	int mass;
	std::map<std::pair<int, int>, std::pair<double, double>> accelMap;
public:
	static_mass(int nx, int ny, int nmass);
	int get_x() {return x;}
	int get_y() {return y;}
	int get_mass() {return mass;}
	void map_accel(int rows, int cols);
};

void carsoneffect();

#endif
